#include <bits/stdc++.h>

using namespace std;

int N, M;
int val[8];

void bt(int cnt){

    if (cnt == M){
        for(int i = 0; i < M; i++){
            cout << val[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < N; i++){
        val[cnt] = i + 1;
        bt(cnt+1);
    }

}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    bt(0);

}
