#include <bits/stdc++.h>
#define MAX 100010

using namespace std; 

vector<vector<int>> graph(MAX);
bool visited[MAX] = {false};
int N, K;
pair<int, int> front = {0, -1};
queue<pair<int, int>> q; 

bool include(int num){
    return num >= 0 && num < MAX;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < MAX; i++){
        if (include(i-1)) graph[i].push_back(i-1);
        if (include(i+1)) graph[i].push_back(i+1);
        if (include(i*2)) graph[i].push_back(i*2);
    }

    cin >> N >> K;
    q.push({0, N});
    while(true){
        pair<int, int> top_pair = q.front();
        q.pop();
        int lev = top_pair.first, val = top_pair.second;
        if (val == K){
            cout << lev; 
            break;
        }
        visited[val] = true;
        if (include(val+1) && !visited[val + 1]) q.push({lev + 1, val + 1});
        if (include(val-1) && !visited[val - 1]) q.push({lev + 1, val - 1});
        if (include(val*2) && !visited[val * 2]) q.push({lev + 1, val * 2});
    }
 
}
