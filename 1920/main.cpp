#include <iostream>

using namespace std;
using ll = long long;

ll A, B, C;

ll pow(ll a, ll b){
    if(b == 0) return 1;
    ll half = pow(a, b/2);
    ll ret = half * half % C;
    if (b % 2 == 1) {ret *= a; ret %= C;}
    return ret;
}

int main()
{
    cin >> A >> B >> C;
    cout << pow(A, B);

}
