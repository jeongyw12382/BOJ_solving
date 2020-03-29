#include <bits/stdc++.h>
#define MAX 501

using namespace std;

struct edge{
    int from;
    int to; 
    int weight;
};

int dist[MAX], N, M, from, to, weight;
vector<edge> graph;

int main(){

    fill(dist, dist+MAX, INT_MAX);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> from >> to >> weight;
        graph.push_back({from-1, to-1, weight});
    }

    dist[0] = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int src = graph[j].from;
            int dest = graph[j].to;
            int w = graph[j].weight;
            if (dist[src] != INT_MAX && dist[dest] > dist[src] + w){
                dist[dest] = dist[src] + w;
            }
        }
    }

    for(int i = 0; i < M; i++){
        int src = graph[i].from;
        int dest = graph[i].to;
        int w = graph[i].weight;
        if (dist[src] != INT_MAX && dist[dest] > dist[src] + w){
            cout << -1;
            return 0;
        }
    }
    
    for(int i = 1; i < N; i++){
        cout << (dist[i] == INT_MAX ? -1 : dist[i]) << '\n';
    }

}