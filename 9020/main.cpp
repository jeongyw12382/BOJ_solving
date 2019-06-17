#include <iostream>
#include <cmath>

using namespace std;

int T, N;
bool isprime[100000] = {false};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int max_iter = sqrt(10000);
    isprime[0] = true; isprime[1] = true;
    for(int i = 2; i <= max_iter; i++){
        if (isprime[i]) continue;
        for(int j = 2; j <= 10000 / i; j++){
            isprime[i * j] = true;
        }
    }

    for(cin >> T; T > 0; T--){
        cin >> N;
        for(int i = N / 2; i >= 0; i--){
            if(!isprime[i] && !isprime[N - i]){
                cout << i << ' ' << N - i << '\n';
                break;
            }
        }
    }
}
