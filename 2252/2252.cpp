#include <bits/stdc++.h>
#define MAX 32001

using namespace std;

using vvi=vector<vector<int>>;

int N, M, from, to;
vvi graph(MAX);
int cnt[MAX] = {0};
queue<int> q;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i = 0 ; i < M; i++){
        cin >> from >> to;
        graph[from-1].push_back(to-1);
        cnt[to-1]++;
    }

    for(int i = 0; i < N; i++){
        if(!cnt[i]) q.push(i);
    }

    while(!q.empty()){
        int top = q.front();
        cout << top + 1 << ' ';
        q.pop();
        for(int i = 0; i < graph[top].size(); i++){
            cnt[graph[top][i]]--;
            if(!cnt[graph[top][i]]){
                q.push(graph[top][i]);
            }
        }
    }


}