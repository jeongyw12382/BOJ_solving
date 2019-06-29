#include <bits/stdc++.h>

using namespace std;

int N;
char star[6562][6562];
const pair<const int, const int> dir[8] = {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};

void draw(int x, int y, int n){
    if (n == 1){
        for(int i = 0; i < 8; i++){
            star[x + dir[i].first][y + dir[i].second] = '*';
        }
        return;
    }
    int scale = pow(3, n-1);
    for(int i = 0; i < 8; i++){
        draw(x + scale * dir[i].first, y + scale * dir[i].second, n-1);
    }
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            star[i][j] = ' ';
        }
    }
    draw(0, 0, (int)(log((float)(N))/log(3.0)));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << star[i][j] ;
        }
        if(i != N-1) cout << '\n';
    }

}
