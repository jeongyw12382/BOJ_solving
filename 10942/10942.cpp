#include <bits/stdc++.h>

using namespace std; 

bool dp[2001][2001] = {false};
int arr[2001];
int N, M, S, E;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        dp[i][i] = true;
    }

    for(int len = 1; len < N; len++){
        for(int st = 0; st + len < N; st++){
            if(arr[st] == arr[st + len]){
                dp[st][st+len] = len == 1 || dp[st+1][st+len-1];
            }
        }
    }

    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> S >> E;
        cout << (dp[S-1][E-1] ? 1 : 0) << '\n';
    }

}