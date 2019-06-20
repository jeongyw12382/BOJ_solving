#include <iostream>
#include <algorithm>
#define MAX 100000

using namespace std;

int sticker[2][MAX];
int dp[3][MAX];
bool pasted[2][MAX];
// 0 : sticking nothing behind
// 1 : sticking above sticker
// 2 : sticking below sticker
int T, n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(cin >> T; T > 0; T--){
        cin >> n;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < n; j++){
                cin >> sticker[i][j];
                pasted[i][j] = false;
            }
        }
        dp[0][0] = 0;
        dp[1][0] = sticker[0][0];
        dp[2][0] = sticker[1][0];
        for(int i = 1; i < n; i++){
            dp[0][i] = max(max(dp[0][i-1], dp[1][i-1]), dp[2][i-1]);
            dp[1][i] = max(dp[2][i-1], dp[0][i-1]) + sticker[0][i];
            dp[2][i] = max(dp[1][i-1], dp[0][i-1]) + sticker[1][i];
        }
        int ret = max(max(sticker[0][n-1], sticker[1][n-1]), sticker[2][n-1]);
        cout << ret << '\n';
    }

}
