#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct vec_struct{
    vec<int> vec_inside;
    bool operator<(const vec_struct& other){ return vec_inside.size() < other.vec_inside.size(); }
};

vector< vector<int> > edge;
vector< vector<int> > vert_div;
int V, E;
int src, dst, idx = 0;
bool visited[10001];

void dfs(int i, vector< vector<int> > vert_div, int idx){

    vert_div[idx].push_back(i);
    bool& visit_change = visited[i];
    visit_change = true;
    for(int j = 0; j < edge[i].size(); j++){
        if (!visited[edge[i][j]]) dfs(edge[i][j], vert_div, idx);
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E;

    for(int i = 0; i < V; i++){
        vector<int> edge_vec;
        edge.push_back(edge_vec);
    }

    for(int i = 0; i < E; i++){
        cin >> src >> dst;
        edge[src-1].push_back(dst-1);
        edge[dst-1].push_back(src-1);
    }

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            visited[i] = true;
            vec_struct vert_div_vect;
            vert_div.push_back(vert_div_vec);
            dfs(i, vert_div, idx);
            idx++;
        }
    }

    vector<int> max_val = max_element(vert_div.begin(), vert_div.end());

    for(int i = 0; i < vert_div[0].size(); i++){
        cout << vert_div[0][i] << '\n';
    }

}
