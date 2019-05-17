#include <iostream>
#include <queue>
#include <algorithm>

#define MAX_VAL -1e-9

using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int M, N, max_val = MAX_VAL;
int graph[1001][1001];
queue< pair <int, int> > que;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> graph[i][j];
            if (graph[i][j] == 1) que.push({i, j});
        }
    }

    while(!que.empty()){
        pair <int, int> front_val = que.front();
        que.pop();

        int x = front_val.second;
        int y = front_val.first;

        for(int i = 0 ; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if(graph[ny][nx] == 0){
                graph[ny][nx] = graph[y][x] + 1;
                que.push({ny, nx});
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(graph[i][j] == 0){
                cout << -1;
                return 0;
            }
            max_val = max(max_val, graph[i][j]);
        }
    }

    cout << max_val - 1;

}
