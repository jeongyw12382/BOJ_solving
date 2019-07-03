#include <bits/stdc++.h>

using namespace std;

int arr[10000], N; 
int dp[10001] = {0};
int max_val = INT_MIN;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    dp[0] = 0;
    dp[1] = arr[0];
    dp[2] = arr[0] + arr[1];
    for(int i = 3; i <= N; i++){
        dp[i] = max(dp[i-2] + arr[i-1], dp[i-1]);
        dp[i] = max(dp[i], dp[i-3] + arr[i-1] + arr[i-2]);
    }
    for(int i = 0; i <= N; i++){max_val = max(max_val, dp[i]);}
    cout << max_val;
}
