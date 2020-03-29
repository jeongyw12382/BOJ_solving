#include <bits/stdc++.h>

using namespace std; 

int f, s, g, u, d;
int dist[1000001];
queue<int> q;

bool valid(int i){
    return 0 <= i && i < f;
}

int main(){

    cin >> f >> s >> g >> u >> d;
    fill(dist, dist + 1000001, -1);
    
    q.push(s-1);
    dist[s-1] = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        if(valid(front + u) && dist[front + u] == -1){
            dist[front + u] = dist[front] + 1;
            q.push(front + u);
        }
        if(valid(front - d) && dist[front - d] == -1){
            dist[front - d] = dist[front] + 1;
            q.push(front - d);
        }
    }

    if(dist[g-1] == -1) cout << "use the stairs";
    else cout << dist[g-1];

}