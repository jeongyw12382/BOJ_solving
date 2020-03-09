#include <bits/stdc++.h>

using namespace std;

int T; 
int cnt, K, X, Y, M, N; 
bool arr[51][51] = {false};

void dfs(int i, int j){
    if(i < 0 || i >= N || j < 0 || j >= M || !arr[i][j]) return;
    arr[i][j] = false;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(cin >> T; T > 0; T--){

        cin >> M >> N >> K;
        cnt = 0;
        for(int i = 0; i < K; i++){
            cin >> X >> Y;
            arr[Y][X] = true;
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(arr[i][j]){
                    cnt++;
                    dfs(i, j);
                }
            }
        }

        cout << cnt << '\n' ;

    }

}