#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int N;
ll B, val;

vector<vector<ll>> matmul(vector<vector<ll>> mat1, vector<vector<ll>> mat2){
    vector<vector<ll>> ret(N, vector<ll>(N, 0));
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            for(ll k = 0; k < N; k++){
                ret[i][j] += mat1[i][k] * mat2[k][j];
                ret[i][j] %= 1000;
            }
        }
    }
    return ret;
}

vector<vector<ll>> pow(vector<vector<ll>> mat, ll curr_B){
    if (curr_B == 0){
        vector<vector<ll>> ret(N, vector<ll>(N, 0));
        for(int i = 0; i < N; ++i) {ret[i][i] = 1;}
        return ret;
    }
    vector<vector<ll>> half = pow(mat, curr_B/2);
    vector<vector<ll>> ret = matmul(half, half);
    if(curr_B % 2 == 1) ret = matmul(ret, mat);
    return ret;
}

int main()
{
    cin >> N >> B;
    vector<vector<ll>> mat(N, vector<ll>(N, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> mat[i][j];
        }
    }

    vector<vector<ll>> ret = pow(mat, B);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << ret[i][j] % 1000 << ' ';
        }
        cout << '\n';
    }

}
