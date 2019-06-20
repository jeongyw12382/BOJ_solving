#include <iostream>
#include <algorithm>

using namespace std;

long long A, B;

long long gcd(long long a, long long b){
    if(max(a,b) % min(a,b) == 0) return min(a,b);
    return gcd(max(a,b) % min(a,b), min(a,b));
}

long long lcm(long long a, long long b){
    return a * b / gcd(a,b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> B;
    cout << lcm(A, B);

}
