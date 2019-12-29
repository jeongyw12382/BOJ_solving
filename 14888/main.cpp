#include <bits/stdc++.h>

using namespace std;

int N, num[20], oper[4];
int min_val = 1e9+1, max_val = -1e9-1, curr_val;

int esti(int x, int y, int oper){
    return oper == 0 ? x + y : oper == 1 ? x - y : oper == 2 ? x * y : x / y;
}

void solve(int op_done){

    if (op_done == N-1){
        max_val = max_val < curr_val ? curr_val : max_val;
        min_val = min_val > curr_val ? curr_val : min_val;
        return;
    }

    for(int i = 0; i < 4; i++){
        if (oper[i] != 0){
            oper[i]--;
            int save_val = curr_val;
            curr_val = esti(curr_val, num[op_done+1], i);
            solve(op_done + 1);
            curr_val = save_val;
            oper[i]++;
        }
    }

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) { cin >> num[i]; }
    for(int i = 0; i < 4; i++) { cin >> oper[i]; }
    curr_val = num[0];

    solve(0);

    cout << max_val << '\n' << min_val;

}
