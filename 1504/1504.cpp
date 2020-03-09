#include <bits/stdc++.h>

#define MAX 801

using namespace std; 

int src, dest, weight, p1, p2, N, E;
int dist_src[MAX], dist_dest[MAX], dist_p1[MAX];
bool visited_src[MAX] = {false}, visited_dest[MAX] = {false}, visited_p1[MAX] = {false};
long long d1 = 0, d2 = 0;

vector<vector<pair<int, int>>> graph(MAX);

void dijskstra(int start, int* dist, bool* visited){
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    visited[start] = true;
    while(!pq.empty()){
        pair<int, int> top = pq.top();
        pq.pop();
        int curr_dist = -top.first;
        int curr_src = top.second;
        visited[curr_src] = true;
        for(int i = 0; i < graph[curr_src].size(); i++){
            int curr_dest = graph[curr_src][i].first;
            int curr_weight = graph[curr_src][i].second;
            if (visited[curr_dest]) continue;
            if(dist[curr_dest] == -1 || dist[curr_dest] >= curr_weight + curr_dist){
                dist[curr_dest] = curr_weight + curr_dist;
                pq.push({-(curr_weight + curr_dist), curr_dest});
            }
        }
    }
}


int main(){

    fill(dist_src, dist_src + MAX, -1);
    fill(dist_dest, dist_dest + MAX, -1);
    fill(dist_p1, dist_p1 + MAX, -1);

    cin >> N >> E;
    for(int i = 0; i < E; i++){
        cin >> src >> dest >> weight;
        graph[src-1].push_back({dest-1, weight});
        graph[dest-1].push_back({src-1, weight});
    }
    cin >> p1 >> p2;

    dijskstra(0, dist_src, visited_src);
    dijskstra(p1-1, dist_p1, visited_p1);
    dijskstra(N-1, dist_dest, visited_dest);

    bool pred1 = dist_src[p1-1] == -1 || dist_p1[p2-1] == -1 || dist_dest[p2-1] == -1;
    d1 = pred1 ? LLONG_MAX : ((long long) dist_src[p1-1]) + dist_p1[p2-1] + dist_dest[p2-1];

    bool pred2 = dist_src[p2-1] == -1 || dist_p1[p2-1] == -1 || dist_dest[p1-1] == -1;
    d2 = pred2 ? LLONG_MAX : ((long long) dist_src[p2-1]) + dist_p1[p2-1] + dist_dest[p1-1];

    bool pred3 = d1 == LLONG_MAX && d2 == LLONG_MAX;
    long long ret = pred3 ? -1 : min(d1, d2);

    cout << ret;

}