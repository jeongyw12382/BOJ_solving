#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct pair_3d{
    int x;
    int y;
    int z;
    pair_3d(int new_x, int new_y, int new_z){
        x = new_x;
        y = new_y;
        z = new_z;
    }
};

const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};

int graph[101][101][101];
int max_val = INT_MIN;
int M, N, H;
queue<pair_3d> que;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N >> H;

    // i : z, j : y, k : x
    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                cin >> graph[i][j][k];
                if (graph[i][j][k] == 1){
                    pair_3d pair_input(k, j, i);
                    que.push(pair_input);
                }
            }
        }
    }

    while(!que.empty()){
        pair_3d front_val = que.front();
        que.pop();

        for(int i = 0; i < 6; i++){
            int nx = front_val.x + dx[i];
            int ny = front_val.y + dy[i];
            int nz = front_val.z + dz[i];
            if (nx < 0 || ny < 0 || nz < 0 || nx >= M || ny >= N || nz >= H) continue;
            if (graph[nz][ny][nx] == 0){
                graph[nz][ny][nx] = graph[front_val.z][front_val.y][front_val.x] + 1;
                pair_3d pair_input(nx, ny, nz);
                que.push(pair_input);
            }
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                if (graph[i][j][k] == 0) {cout << -1; return 0;}
                max_val = max(max_val, graph[i][j][k]);
            }
        }
    }

    cout << max_val - 1;

}
