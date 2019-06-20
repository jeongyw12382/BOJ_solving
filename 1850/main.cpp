#include <iostream>

using namespace std;

long long A, B;

long long gcd(long long a, long long b){
    if (max(a,b) % min(a,b) == 0) return min(a,b);
    return gcd(max(a,b) % min(a,b), min(a,b));
}


int main()
{
    cin >> A >> B;
    for(int i = 0; i < gcd(A,B); i++) cout << 1;
}
