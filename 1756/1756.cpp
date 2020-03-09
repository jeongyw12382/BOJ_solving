#include <bits/stdc++.h>

#define MAX 20001

using namespace std;

int V, E, init, from, to, weight;
vector<vector<pair<int, int>>> graph(MAX);
int dist[MAX];
bool visited[MAX] = {false};
priority_queue<pair<int, int>> pq; 

int main(){
    
    fill(dist, dist+MAX, -1);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> V >> E >> init;

    for(int i = 0; i < E; i++){
        cin >> from >> to >> weight;
        graph[from-1].push_back({to-1, weight});
    }

    dist[init-1] = 0;
    visited[init-1] = true;
    pq.push({0, init-1});

    while(!pq.empty()){
        pair<int, int> top = pq.top();
        pq.pop();
        int src = top.second;
        int curr_dist = -top.first;
        visited[src] = true;
        for(int i = 0; i < graph[src].size(); i++){
            int dest = graph[src][i].first;
            int weight = graph[src][i].second;
            if (visited[dest]) continue;
            if (dist[dest] == -1 || dist[dest] >= curr_dist + weight){
                dist[dest] = curr_dist + weight;
                pq.push({-(curr_dist + weight), dest});
            }
        }
    }

    for(int i = 0; i < V; i++){
        if (dist[i] == -1) cout << "INF";
        else cout << dist[i];
        cout << '\n';
    }

}