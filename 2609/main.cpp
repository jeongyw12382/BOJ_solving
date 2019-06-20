#include <iostream>
#include <algorithm>

using namespace std;

int A, B;

int gcd(int a, int b){
    if (max(a,b) % min(a,b) == 0) return min(a,b);
    else return gcd(max(a,b) % min(a,b), min(a,b));
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> B;
    cout << gcd(A,B) << '\n' << lcm(A, B);
}
