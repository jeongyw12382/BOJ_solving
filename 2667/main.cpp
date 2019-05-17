#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char input_line[30];
int N;
vector<int> num_house;

const int dir_x[] = {1,-1,0,0};
const int dir_y[] = {0,0,1,-1};

int dfs(pair <int, int> curr, int graph[30][30], bool visited[30][30]);

int main()
{
    /*
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    */

    int graph[30][30];
    bool visited[30][30] = {false};

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input_line;
        for(int j = 0 ; j < N; j++){
            graph[i][j] = input_line[j] - '0';
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if (!visited[i][j] && graph[i][j] == 1){
                visited[i][j] = true;
                num_house.push_back(dfs({i, j}, graph, visited));
            }
        }
    }

    sort(num_house.begin(), num_house.end());
    cout << num_house.size() << '\n';
    for(int i = 0; i < num_house.size(); i++){
        cout << num_house[i] << '\n';
    }

}

int dfs(pair <int, int> curr, int graph[30][30], bool visited[30][30]){
    int y = curr.first;
    int x = curr.second;
    int cnt = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dir_y[i];
        int nx = x + dir_x[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if (!visited[ny][nx] && graph[ny][nx] == 1){
            visited[ny][nx] = true;
            cnt += dfs({ny, nx}, graph, visited);
        }
    }
    return cnt;
}
