#include <bits/stdc++.h>

using namespace std;

int dp[510][510] = {0}, N;
pair<int, int> mat[501];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> mat[i].first >> mat[i].second;
    }

    for(int len = 1; len < N; len++){
        for(int i = 0; i + len < N; i++){
            dp[i][i+len] = INT_MAX;
            for(int k = i; k + 1 <= i+len; k++){
                dp[i][i+len] = min(dp[i][i+len], dp[i][k] + dp[k+1][i+len] +
                                   mat[i].first * mat[k].second * mat[i+len].second);
            }
        }
    }

    cout << dp[0][N-1];

}
