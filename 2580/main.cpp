#include <bits/stdc++.h>

using namespace std;

int board[9][9] = {0}, blank_size;
vector<pair<int, int>> blank;
bool bitmap[81] = {false};

bool possible(int y, int x, int num){
    for(int i = 0; i < 9; i++){
        if (board[i][x] == num) return false;
        if (board[y][i] == num) return false;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (board[(y/3)*3+i][(x/3)*3+j] == num) return false;
        }
    }
    return true;
}

void print(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool solve(int curr_blank){

    if (curr_blank == blank_size){
        print();
        return true;
    }

    pair<int, int> curr = blank[curr_blank];
    for(int i = 1; i <= 9; i++){
        if (possible(curr.first, curr.second, i)){
            board[curr.first][curr.second] = i;
            bool ret = solve(curr_blank + 1);
            if (ret) return true;
            board[curr.first][curr.second] = 0;
        }
    }
    return false;

}


int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> board[i][j];
            if(board[i][j] == 0){
                blank.push_back({i, j});
            }
        }
    }

    blank_size = blank.size();

    memset(bitmap, true, blank_size);
    solve(0);

}
