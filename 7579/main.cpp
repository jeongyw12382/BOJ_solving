#include <bits/stdc++.h>

using namespace std;

int N, M, c[100], m[100];
int dp[10001] = {0};
int sum = 0;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> m[i];
    for(int i = 0; i < N; i++) {
        cin >> c[i];
        sum += c[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = sum; j >= c[i]; j--){
            dp[j] = max(dp[j], dp[j-c[i]] + m[i]);
        }
    }
    int i;
    for(i = 0; i < sum && dp[i] < M; i++);
    cout << i;
}
