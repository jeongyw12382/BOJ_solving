#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, vert1, vert2;
vector< vector<int> > edge;
queue< int > q;
bool visited[100001] = {false};
int parent[100001] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        vector<int> edge_vec;
        edge.push_back(edge_vec);
    }
    for(int i = 0; i < N-1; i++){
        cin >> vert1 >> vert2;
        edge[vert1-1].push_back(vert2-1);
        edge[vert2-1].push_back(vert1-1);
    }

    visited[0] = true;
    q.push({0});
    while(!q.empty()){
        int front_val = q.front();
        q.pop();
        visited[front_val] = true;
        for(int i = 0; i < edge[front_val].size(); i++){
            if (visited[edge[front_val][i]]) continue;
            else{
                q.push({edge[front_val][i]});
                parent[edge[front_val][i]] = front_val + 1;
            }
        }
    }

    for(int i = 1; i < N; i++){
        cout << parent[i] << '\n';
    }

}
