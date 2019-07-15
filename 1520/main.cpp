#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll arr[500][500], dp[501][501], N, M;
const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

ll dfs(int y, int x){
    if(y == 0 && x == 0) return dp[0][0];
    dp[y][x] = 0;
    for(int i = 0; i < 4; i++){
        int new_y = y + dir[i][0];
        int new_x = x + dir[i][1];
        if(new_y < 0 || new_y > N-1 || new_x < 0 || new_x > M-1) continue;
        if(dp[new_y][new_x] != -1 && arr[new_y][new_x] > arr[y][x]) dp[y][x] += dp[new_y][new_x];
        else if(arr[new_y][new_x] > arr[y][x]) dp[y][x] += dfs(new_y, new_x);
    }
    return dp[y][x];
}

int main()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) cin >> arr[i][j];
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 1;
    cout << dfs(N-1, M-1);

}
