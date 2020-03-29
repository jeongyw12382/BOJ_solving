#include <bits/stdc++.h>
#define MAX 501

using namespace std;

struct edge{
    int from;
    int to;
    int weight;
};

using ve=vector<edge>;

int F, N, M, W, S, E, T;
int dist[MAX];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(cin >> F; F > 0; F--){
        cin >> N >> M >> W;
        ve graph(MAX);
        fill(dist, dist+MAX, INT_MAX);
        dist[0] = 0;
        for(int i = 0; i < M; i++){
            cin >> S >> E >> T;
            graph.push_back({S-1, E-1, T});
            graph.push_back({E-1, S-1, T});
        }
        for(int i = 0; i < W; i++){
            cin >> S >> E >> T;
            graph.push_back({S-1, E-1, -T});
        }
        
        for(int i = 0; i < N-1; i++){
            for(int j = 0; j < graph.size(); j++){
                edge e = graph[j];
                if(dist[e.from] != INT_MAX && dist[e.to] >= dist[e.from] + e.weight){
                    dist[e.to] = dist[e.from] + e.weight;
                }
            }
        }

        bool exist = false;
        for(int i = 0; i < graph.size(); i++){
            edge e = graph[i];
            if(dist[e.from] != INT_MAX && dist[e.to] > dist[e.from] + e.weight){
                cout << "YES\n";
                exist = true;
                break;
            }
        }
        if (!exist){
            cout << "NO\n";
        }
    }

}