#include <bits/stdc++.h>

using namespace std;

int N, K;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    int l = 0, h = K;
    while(l <= h){
        int m = (l + h) / 2;
        int cnt = 0;
        for(int i = 1; i <= N; i++){
            cnt += min(N, m / i);
        }
        if (cnt < K){
            l = m + 1;
        } else{
            h = m - 1;
        }
    }
    cout << l;
}
