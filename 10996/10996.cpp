#include <bits/stdc++.h>

using namespace std;

int N;

int main(){

    cin >> N;
    for(int i = 0; i < 2 * N; i++){
        for(int j = 0; j < N; j++){
            if(j == N-1 && (i + j) % 2 == 1) break;
            cout << ((i + j) % 2 == 0 ? '*' : ' ');
        }
        if(N != 1) cout << '\n';
    }

}