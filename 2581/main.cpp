#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

int N, M;
int min_val = INT_MAX, sum = 0;
bool prime_exist = false;

bool isprime(int N){
    if (N == 1) return false;
    if (N == 2) return true;
    int root_n = ceil(sqrt(N));
    bool ret = true;
    for(int i = 2; i <= root_n; i++){
        if (N % i == 0) ret = false;
    }
    return ret;
}

int main()
{
    cin >> M >> N;
    for(int i = M; i <= N; i++){
        if (isprime(i)){
            prime_exist = true;
            min_val = min(min_val, i);
            sum += i;
        }
    }
    if (prime_exist) { cout << sum << ' ' << min_val; }
    else {cout << -1;}

}
