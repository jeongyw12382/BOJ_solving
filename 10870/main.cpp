#include <iostream>

using namespace std;

long long fibo(int N){
    if(N == 0) return 0;
    if(N == 1) return 1;
    return fibo(N-1) + fibo(N-2);
}

int main()
{
    int N;
    cin >> N;
    cout << fibo(N);
}
