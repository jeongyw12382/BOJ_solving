#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int dist_arr[100001] = {0};
vector< vector<pair<int, int>> > edge;
bool visited[100001] = {false};
int dep, dest, dist;
int x,y;

void dfs(int point){
    visited[point] = true;
    for(int i = 0; i < edge[point].size(); i++){
        if(visited[edge[point][i].first]) continue;
        dist_arr[edge[point][i].first] = dist_arr[point] + edge[point][i].second;
        dfs(edge[point][i].first);
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        vector<pair<int, int>> edge_vec;
        edge.push_back(edge_vec);
    }
    for(int i = 0; i < N; i++){
        cin >> dep;
        while(1){
            cin >> dest;
            if (dest == -1) break;
            cin >> dist;
            edge[dep-1].push_back({dest-1, dist});
        }
    }

    dfs(0);
    x = max_element(dist_arr, dist_arr + N) - dist_arr;
    for(int i = 0; i < N; i++){visited[i] = false; dist_arr[i] = 0;}
    dfs(x);
    cout << *max_element(dist_arr, dist_arr + N);
}
