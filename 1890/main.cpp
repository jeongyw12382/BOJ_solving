#include <iostream>
#include <queue>

using namespace std;

int N;
int board[101][101];
long long way[101][101] = {0};
int cnt = 0;
queue<pair <int, int> > que;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    way[0][0] = 1;
    que.push({0,0});

    while(!que.empty()){
        pair <int, int> front_val = que.front();
        que.pop();
        int x = front_val.second;
        int y = front_val.first;
        if (board[y][x] == 0) continue;
        int nx = x + board[y][x];
        int ny = y + board[y][x];
        if (nx < N) {que.push({y, nx}); way[y][nx] += way[y][x];}
        if (ny < N) {que.push({ny, x}); way[ny][x] += way[y][x];}
    }

    cout << way[N-1][N-1];

}
