#include <bits/stdc++.h>

using namespace std;

int arr[1000], N;
int dp[1000] = {0};
int ret;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    dp[0] = 1;
    ret = dp[0];
    for(int i = 1; i < N; i++){
        int max_val = 1;
        for(int j = 0; j < i; j++){
            if (arr[j] < arr[i]) max_val = max(max_val, dp[j] + 1);
        }
        dp[i] = max_val;
        ret = max(ret, dp[i]);
    }
    cout << ret;
}