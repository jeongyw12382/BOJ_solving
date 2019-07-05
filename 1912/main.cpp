#include <bits/stdc++.h>

using namespace std;

int N, arr[100000], dp[100001] = {0}, max_val = INT_MIN;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    dp[0] = arr[0] > 0 ? arr[0] : 0;
    for(int i = 0; i < N; i++){
        dp[i] = (dp[i-1] < 0 ? arr[i] : dp[i-1] + arr[i]);
    }
    for(int i = 0; i < N; i++){
        max_val = max(max_val, dp[i]);
    }

    cout << max_val;

}