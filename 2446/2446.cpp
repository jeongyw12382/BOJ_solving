#include <bits/stdc++.h>

using namespace std;
int N;

void plot(char s, int num){
    for(int i = 0; i < num; i++) cout << s;
}


int main(){

    cin >> N;

    for(int i = 0; i < N; i++){
        plot(' ', i);
        plot('*', 2 * N - 1 - 2 * i);
        cout << '\n';
    }

    for(int i = N-2; i >= 0; i--){
        plot(' ', i);
        plot('*', 2 * N - 1 - 2 * i);
        cout << '\n';
    }

}