#include <iostream>
#include <cmath>

using namespace std;

bool isprime[90000000] = {false};
int M, N, max_iter;

int main()
{
    cin >> M >> N;
    max_iter = ceil(sqrt(N));
    isprime[0] = true;
    isprime[1] = true;
    for(int i = 2; i <= max_iter; i++){
        if (!isprime[i]){
            for(int j = 2; j <= N / i; j++){
                isprime[i * j] = true;
            }
        }
    }

    for(int i = M; i <= N; i++){
        if(!isprime[i]){
            cout << i << '\n';
        }
    }

}
