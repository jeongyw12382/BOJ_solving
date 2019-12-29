#include <bits/stdc++.h>

using namespace std;

int N;
int save[16];
long long nq = 0;

bool isValid(int row, int col){
    for(int i = 0; i < row; i++){
        if(col == save[i] || abs(row - i) == abs(col - save[i])){
            return false;
        }
    }
    return true;
}

void bt(int cnt){

    if (cnt == N){
        nq++;
        return;
    }

    for(int i = 0; i < N; i++){
        if (isValid(cnt, i)){
            save[cnt] = i;
            bt(cnt + 1);
        }
    }

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    bt(0);
    cout << nq;

}
