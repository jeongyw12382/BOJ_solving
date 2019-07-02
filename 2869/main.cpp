#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll A, B, V;

int main()
{
    cin >> A >> B >> V;
    cout << (V - B - 1) /( A - B) + 1;
}
