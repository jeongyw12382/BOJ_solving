#include <bits/stdc++.h>

#define MAX 2001

using namespace std;
using vvp=vector<vector<pair<int, int>>>;
using vpi=vector<pair<int, int>>;

int p1, p2, n, m, t, T, s, from, to, weight, cand;
int dist_p1[MAX], dist_p2[MAX], dist_start[MAX];

void dijkstra(int start, int* dist, vvp graph){
    priority_queue<pair<int, int>> pq;
    bool visited[MAX] = {false};
    visited[start] = true;
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()){
        int curr_dist = -pq.top().first;
        int curr_pt = pq.top().second;
        pq.pop();
        visited[curr_pt] = true;
        for(int i = 0; i < graph[curr_pt].size(); i++){
            int curr_desc = graph[curr_pt][i].first;
            int curr_weight = graph[curr_pt][i].second;
            if (visited[curr_desc]) continue;
            if (dist[curr_desc] == -1 || dist[curr_desc] >= curr_weight + curr_dist){
                dist[curr_desc] = curr_weight + curr_dist;
                pq.push({-(curr_weight + curr_dist), curr_desc});
            }
        }
    }
}

int dist_calc(int start, int dest, int w){ 
    bool pred1 = dist_p1[start] == -1 || dist_p2[dest] == -1;
    int d1 = pred1 ? INT_MAX : dist_p1[start] + dist_p2[dest];
    bool pred2 = dist_p1[dest] == -1 || dist_p1[start] == -1;
    int d2 = pred2 ? INT_MAX : dist_p1[dest] + dist_p2[start];
    bool pred3 = (d1 == INT_MAX && d2 == INT_MAX);
    return pred3 ? -1 : (min(d1, d2) + w);
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(cin >> T; T > 0; T--){
        vvp graph(MAX);
        vpi ret;

        fill(dist_p1, dist_p1 + MAX, -1);
        fill(dist_p2, dist_p2 + MAX, -1);
        fill(dist_start, dist_start + MAX, -1);

        cin >> n >> m >> t;
        cin >> s >> p1 >> p2;
        for(int i = 0 ; i < m; i++){
            cin >> from >> to >> weight;
            graph[from-1].push_back({to-1, weight});
            graph[to-1].push_back({from-1, weight});
        }
        
        dijkstra(p1-1, dist_p1, graph);
        dijkstra(p2-1, dist_p2, graph);
        dijkstra(s-1, dist_start, graph);

        for(int i = 0; i < t; i++){
            cin >> cand;
            int curr_dist = -1;
            for(int j = 0; j < graph[p1-1].size(); j++){
                if (graph[p1-1][j].first == p2-1){
                    curr_dist = dist_calc(s-1, cand-1, graph[p1-1][j].second);
                }
            }
            if(curr_dist != -1 && curr_dist == dist_start[cand-1]){
                ret.push_back({cand, curr_dist});
            }
        }
        sort(ret.begin(), ret.end());

        for(int i = 0; i < ret.size(); i++) {
            cout << ret[i].first << ' ';
        }

        cout << '\n';

    }


}