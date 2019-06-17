#include <iostream>
#include <cmath>

using namespace std;

int N;
char star[10000][10000];

void star_draw(int y, int x, int n){

    if (n == 0){
        star[y][x] = '*';
        star[y+1][x+1] = '*';
        star[y+1][x-1] = '*';
        star[y+2][x-2] = '*';
        star[y+2][x-1] = '*';
        star[y+2][x] = '*';
        star[y+2][x+1] = '*';
        star[y+2][x+2] = '*';
    }

    else{
        int pow_2 = pow(2, n-1);
        star_draw(y, x, n - 1);
        star_draw(y + 3 * pow_2, x - 3 * pow_2, n - 1);
        star_draw(y + 3 * pow_2, x + 3 * pow_2, n - 1);
    }

}


int main()
{
    cin >> N;
    int lev = log2(N / 3);
    star_draw(0, 3 * pow(2, lev)-1, lev);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N * 2; j++){
            cout << (star[i][j] == '*' ? '*' : ' ');
        }
        if (i != N-1) cout << '\n';
    }
}
