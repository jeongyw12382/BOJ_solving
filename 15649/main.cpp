#include <bits/stdc++.h>

using namespace std;

int N, M;
bool used[9] = {false};
int val[9];

void bt(int depth){

    if (depth == M){
        for(int i = 0; i < M; i++){
            cout << val[i] << ' ';
        }
        cout << '\n';
    }

    for(int i = 0; i < N; i++){
        if(used[i]) continue;
        used[i] = true;
        val[depth] = i + 1;
        bt(depth + 1);
        used[i] = false;
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    bt(0);

}
