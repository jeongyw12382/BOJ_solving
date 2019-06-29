#include <iostream>

using namespace std;

int n;

long long fact(int N){
    if(N == 0) return 1;
    return N * fact(N - 1);
}

int main()
{
    cin >> n;
    cout << fact(n);
}
