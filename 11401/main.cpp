#include <bits/stdc++.h>

#define MOD 1000000007
#define ll long long

using namespace std;

int N, K;
ll fact[4000000], x;

int main()
{
    cin >> N >> K;
    fact[0] = 1;
    for(int i = 1; i <= N; i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }

    ll denom = (fact[K] * fact[N - K]) % MOD;
    ll numer = fact[N];

    for(int i = 1; i < MOD; i++){
        if ((i * denom) % MOD == 1){x = i;}
    }
    x %= MOD;
    if(x < 0) x+= MOD;
    cout << x;

}
