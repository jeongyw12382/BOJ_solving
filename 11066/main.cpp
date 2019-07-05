#include <bits/stdc++.h>

using namespace std;

int K, T, arr[501], sum_arr[501], dp[501][501];

int main(){
    for(cin >> T; T--;){
        cin >> K;
        for(int i = 1; i <= K; i++){
            cin >> arr[i];
            sum_arr[i] = sum_arr[i-1] + arr[i];
        }
        // for(int i = 0; i <= K; i++) cout << sum_arr[i] << ' ';
        for(int len = 0; len <= K-1; len++){
            for(int i = 1; i + len <= K; i++){
                if(len == 0){dp[i][i] = 0; continue;}
                if(len == 1){dp[i][i+1] = arr[i] + arr[i+1]; continue;}
                dp[i][i + len] = INT_MAX;
                for(int j = i; j + 1 <= i + len; j++){
                    dp[i][i + len] = min(dp[i][i + len], dp[i][j] + dp[j+1][i + len]\
                    + sum_arr[i + len] - sum_arr[i-1]);
                }
            }
        }
        cout << dp[1][K] << '\n';
    }
}