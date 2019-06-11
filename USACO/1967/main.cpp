#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, from, to, len, max_point;
vector< vector<pair<int, int>> > edge;
int dist[10001] = {0};
bool visited[10001] = {false};

void dfs(int point){
    visited[point] = true;
    for(int i = 0; i < edge[point].size(); i++){
        if (visited[edge[point][i].first]) continue;
        dist[edge[point][i].first] = dist[point] + edge[point][i].second;
        dfs(edge[point][i].first);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        vector<pair<int,int>> edge_vec;
        edge.push_back(edge_vec);
    }
    for(int i = 1; i < N; i++){
        cin >> from >> to >> len;
        edge[from-1].push_back({to-1, len});
        edge[to-1].push_back({from-1, len});
    }

    dfs(0);
    max_point = max_element(dist, dist + N) - dist;
    for(int i = 0; i < N; i++) {dist[i] = 0; visited[i] = false;}
    dfs(max_point);
    cout << *max_element(dist, dist+N);

}
