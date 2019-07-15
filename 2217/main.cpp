#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, arr[100000], val = 0;

int main()
{
    cin >> N;
    for(ll i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    for(ll i = 0; i < N; i++) {val = max(val, (N - i) * arr[i]);}
    cout << val << '\n';

}
