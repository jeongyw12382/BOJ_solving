#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph(101);

int vertex_num, edge_num, from, to, src, dst;
int dist[101];
queue<int> bfs_q;
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill(dist, dist + 101, -1);

    cin >> vertex_num >> from >> to >> edge_num;
    for(int _ = 0; _ < edge_num; _++){
        cin >> src >> dst;
        graph[src-1].push_back(dst-1);
        graph[dst-1].push_back(src-1);
    }

    dist[from-1] = 0;
    bfs_q.push(from-1);
    while(!bfs_q.empty()){
        int front = bfs_q.front();
        bfs_q.pop();
        for(int i = 0 ; i < graph[front].size(); i++){
            if(dist[graph[front][i]] == -1) {
                bfs_q.push(graph[front][i]);
                dist[graph[front][i]] = dist[front] + 1;
            }
        }
    }

    cout << dist[to-1];

}