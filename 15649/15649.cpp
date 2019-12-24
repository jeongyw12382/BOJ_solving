#include <bits/stdc++.h>

using namespace std;

int N, M, cnt = 0;
bool used[9] = {false};

void bt(int);

int main() { 
    
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        bt(i);
    }
    return 0;
}

void bt(int idx){
    if (cnt == M) { cout << '\n'; }
    used[idx] = true;
    cnt++;
    for(int i = 0; i < N; i++){
        if (used[i] &&) continue;
        cout << idx + 1 << ' ';
        bt(i);
    }
    used[idx] = false;
    cnt--;
}