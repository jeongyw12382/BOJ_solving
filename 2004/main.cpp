#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, M;

ll num_5(ll num){
    ll cnt = 0;
    while(num != 0){
        cnt += num/5;
        num /= 5;
    }
    return cnt;
}

ll num_2(ll num){
    ll cnt = 0;
    while(num != 0){
        cnt += num/2;
        num /= 2;
    }
    return cnt;
}

int main()
{
    cin >> N >> M;
    cout << min(num_5(N) - num_5(N-M) - num_5(M), num_2(N) - num_2(N-M) - num_2(M));
}
