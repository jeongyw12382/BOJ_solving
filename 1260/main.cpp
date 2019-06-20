#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector< vector<int> > edge;

int N, M, V;
int from, to;
queue<int> bfs_queue;

bool visited_dfs[1000] = {false};
bool visited_bfs[1000] = {false};

void dfs(int v){
    visited_dfs[v] = true;
    cout << v + 1 << ' ';
    for(int i = 0; i < edge[v].size(); i++){
        if (visited_dfs[edge[v][i]]) continue;
        dfs(edge[v][i]);
    }
}

void bfs(int v){
    bfs_queue.push(v);
    while(!bfs_queue.empty()){
        int front_val = bfs_queue.front();
        bfs_queue.pop();
        if (visited_bfs[front_val]) continue;
        visited_bfs[front_val] = true;
        cout << front_val + 1 << ' ';
        for(int i = 0; i < edge[front_val].size(); i++){
            if (visited_bfs[edge[front_val][i]]) continue;
            bfs_queue.push(edge[front_val][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> V;
    for(int i = 0; i < N; i++){
        vector<int> edge_vec;
        edge.push_back(edge_vec);
    }
    for(int i = 0; i < M; i++){
        cin >> from >> to;
        edge[from-1].push_back(to - 1);
        edge[to-1].push_back(from - 1);
    }
    for(int i = 0; i < N; i++){
        sort(edge[i].begin(), edge[i].end());
    }
    dfs(V-1); cout << '\n';
    bfs(V-1);
}
