#include <bits/stdc++.h>
#define MAX 101

using namespace std;

int dist[MAX][MAX];

using namespace std;

int n, m, src, dst, w;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = INT_MAX;
        }
        dist[i][i] = 0;
    }
    
    for(int i = 0; i < m; i++){
        cin >> src >> dst >> w;
        if(dist[src-1][dst-1] == INT_MAX) dist[src-1][dst-1] = w;
        else dist[src-1][dst-1] = min(dist[src-1][dst-1], w);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(dist[j][i] != INT_MAX && 
                    dist[i][k] != INT_MAX &&
                    dist[j][k] >= dist[j][i] + dist[i][k]
                ){
                    dist[j][k] = dist[j][i] + dist[i][k];
                }
            }
        }
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << (dist[i][j] == INT_MAX? 0 : dist[i][j]) << ' ';
        }
        cout << '\n';
    }

}