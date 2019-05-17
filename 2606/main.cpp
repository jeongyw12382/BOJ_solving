#include <iostream>
#include <vector>

using namespace std;

int V, E;
int src, dst, cnt = 0;
vector< vector<int> > edge;
bool visited[101] = {false};

void dfs(int node, int& count);

int main()
{
    cin >> V >> E;
    for(int i = 0 ; i < V; i++){
        vector<int> edge_vec;
        edge.push_back(edge_vec);
    }
    for(int i = 0; i < E; i++){
        cin >> src >> dst;
        edge[src-1].push_back(dst-1);
        edge[dst-1].push_back(src-1);
    }

    visited[0] = true;
    dfs(0, cnt);

    cout << cnt - 1;

}

void dfs(int node, int& count){
    count++;
    for(int i = 0; i < edge[node].size(); i++){
        if (!visited[edge[node][i]]){
            visited[edge[node][i]] = true;
            dfs(edge[node][i], count);
        }
    }

}

