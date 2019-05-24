#include <iostream>

using namespace std;

int N;
int board[101][101];
long long way[101][101] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    way[0][0] = 1;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if (board[i][j] == 0) continue;
            if (i + board[i][j] < N) way[i + board[i][j]][j] += way[i][j];
            if (j + board[i][j] < N) way[i][j + board[i][j]] += way[i][j];
        }
    }

    cout << way[N-1][N-1];
}
