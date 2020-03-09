#include <bits/stdc++.h>

using namespace std;

struct q_info{
    bool crackable;
    int x;
    int y;
    int dist;
};

// N * M 
bool arr[1001][1001] = {false}, visited[1001][1001][2] = {false};
int N, M;
string input;
queue<q_info> q; 
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j){
    return 0 <= i && i < N && 0 <= j && j < M;
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < M; j++){
            arr[i][j] = input[j] == '0'? false : true;
        }
    }

    q.push({true, 0, 0, 1});
    
    while(!q.empty()){

        q_info front = q.front();
        q.pop();

        bool crackable = front.crackable;
        int x = front.x;
        int y = front.y;
        int dist = front.dist;

        if(visited[y][x][crackable]){
            continue;
        }

        if (y == N-1 && x == M-1){
            cout << dist; 
            return 0; 
        }
        visited[y][x][crackable] = true;

        for(int i = 0; i < 4; i++){
            int new_y = y + dir[i][0];
            int new_x = x + dir[i][1];
            if (!valid(new_y, new_x)) continue;
            if (!arr[new_y][new_x]) q.push({crackable, new_x, new_y, dist + 1});
            if (arr[new_y][new_x] && crackable) q.push({false, new_x, new_y, dist + 1});
        }
    }

    cout << -1;

}