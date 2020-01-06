#include <bits/stdc++.h>

using namespace std;

int N, K;
pair<int, int> input[101];
int dp[110][100010];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> input[i].first >>input[i].second;
    }
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= K; j++){
            dp[i][j] = dp[i-1][j];
            if(j - input[i-1].first >= 0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-input[i-1].first] + input[i-1].second);
            }
        }
    }
    cout << dp[N][K];
}


