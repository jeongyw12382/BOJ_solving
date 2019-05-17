#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int M, N;
int graph[105][105];
int cnt_graph[105][105] = {0};
bool visited[105][105] = {false};
char input[105];
queue < pair<int, int> > que;

const int dir_x[] = {1, -1, 0, 0};
const int dir_y[] = {0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < M; j++){
            graph[i][j] = (input[j] - '0');
        }
    }

    que.push({0,0});
    visited[0][0] = true;

    while(!que.empty()){
        if (cnt_graph[N-1][M-1] != 0) break;
        pair <int, int> front_val = que.front();
        que.pop();
        int y = front_val.first;
        int x = front_val.second;
        for(int i = 0; i < 4; i++){
            int nx = x + dir_x[i];
            int ny = y + dir_y[i];
            if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if(graph[ny][nx] == 1 && !visited[ny][nx]){
                cnt_graph[ny][nx] = cnt_graph[y][x] + 1;
                que.push({ny, nx});
                visited[ny][nx] = true;
            }
        }
    }

    cout << cnt_graph[N-1][M-1] + 1;

}
