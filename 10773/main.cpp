#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, val, sum = 0;
stack<ll> s;

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> val;
        if(val == 0){s.pop();}
        else{s.push(val);}
    }
    for(int i = 0; !s.empty(); i++){
        ll top = s.top();
        sum += top;
        s.pop();
    }

    cout << sum;

    return 0;
}
