#include <iostream>
#include <vector>

using namespace std;

struct TOWER{
    int x;
    int y;
    int R;
};

int T, N;

int dfs(int i, bool visited[3001], vector< vector<int> > edge){
    visited[i] = true;
    for(int j = 0; j < edge[i].size(); j++){
        if (!visited[edge[i][j]]){
            dfs(edge[i][j], visited, edge);
         }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for(; T > 0; T--){
        vector< vector<int> > edge;
        TOWER tower_list[3001];
        bool visited[3001] = {false};
        int cnt = 0;
        cin >> N;
        for(int i = 0; i < N; i++){
            vector<int> edge_vec;
            edge.push_back(edge_vec);
            cin >> tower_list[i].x >> tower_list[i].y >> tower_list[i].R;
        }
        for(int i = 0; i < N; i++){
            for(int j = i+1; j < N; j++){
                int x_1 = tower_list[i].x;
                int x_2 = tower_list[j].x;
                int y_1 = tower_list[i].y;
                int y_2 = tower_list[j].y;
                int R_1 = tower_list[i].R;
                int R_2 = tower_list[j].R;
                int distance = (x_1-x_2)*(x_1-x_2) + (y_1-y_2)*(y_1-y_2);
                if (distance <= (R_1 + R_2) * (R_1 + R_2)) {
                    edge[i].push_back(j);
                    edge[j].push_back(i);
                }
            }
        }
        for(int i = 0; i < N; i++){
            if(!visited[i]){
                cnt++;
                dfs(i, visited, edge);
            }
        }
        cout << cnt << '\n';
    }
}
