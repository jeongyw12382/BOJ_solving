#include <bits/stdc++.h>
#define MAX 101

using namespace std;

struct edge{
    int to;
    int cost;
    int time;
};

struct pq_elem{
    int curr_time;
    int curr_cost;
    int curr_pos;
};

struct pq_elem_cmp{
    bool operator()(pq_elem const& e1, pq_elem const& e2){
        return e1.curr_time < e2.curr_time;
    }
};

using vvp=vector<vector<edge>>;

int N, M, K, u, v, c, d, T;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(cin >> T; T > 0; T--){

        cin >> N >> M >> K;
        vvp graph(MAX);

        for(int i = 0; i < K; i++){
            cin >> u >> v >> c >> d;
            graph[u-1].push_back({v-1, c, d});
        }

        priority_queue<pq_elem, vector<pq_elem>, pq_elem_cmp> pq;

        pq.push({0, 0, 0});

        while(!pq.empty()){
            pq_elem top = pq.top();
            pq.pop();

            int curr_time = -top.curr_time;
            int curr_cost = top.curr_cost;
            int curr_pos = top.curr_pos;


            if(curr_pos == N-1){
                cout << curr_time << '\n';
                break;
            }

            for(int i = 0; i < graph[curr_pos].size(); i++){
                edge e = graph[curr_pos][i];
                int edge_cost = e.cost;
                int edge_time = e.time;
                int edge_pos = e.to;
                if(curr_cost + edge_cost > M) continue;
                pq.push({-(curr_time + edge_time), curr_cost + edge_cost, edge_pos});
            }
        }

        if (pq.empty()){
            cout << "Poor KCM\n";
        }
        
    }


}