#include <bits/stdc++.h>

using namespace std;

int N, board[20][20], min_diff = INT_MAX;
bool contain_list[20];

int score(bool contained){
    int ret = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if (contain_list[i] == contained && contain_list[j] == contained){
                ret +=  board[i][j];
            }
        }
    }
    return ret;
}

void solve(int curr_idx){

    if (curr_idx == N){
        min_diff = min(min_diff, abs(score(true) - score(false)));
        return ;
    }

    for(int i = curr_idx + 1; i <= N; i++){
        if (i == N) {
            solve(N);
            break;
        }
        contain_list[i] = true;
        solve(i);
        contain_list[i] = false;
    }

}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    solve(-1);

    cout << min_diff;

}
