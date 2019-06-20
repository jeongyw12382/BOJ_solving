#include <iostream>
#include <algorithm>

using namespace std;

int T, A, B;

int gcd(int a, int b){
    if (max(a, b) % min(a, b)== 0) return min(a,b);
    return gcd(max(a,b) % min(a,b), min(a, b));
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(cin >> T; T > 0; T--){
        cin >> A >> B;
        cout << lcm(A, B) << '\n';
    }
    return 0;
}
