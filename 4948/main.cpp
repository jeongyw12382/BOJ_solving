#include <iostream>
#include <cmath>

using namespace std;

int N;
bool isprime[500000] = {false};
int cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    isprime[0] = true; isprime[1] = true;
    int max_iter = ceil(sqrt(2 * 200000));
    for(int i = 2; i <= max_iter; i++){
        for(int j = 2; j <= 2 * 200000 / i; j++){
            isprime[i * j] = true;
        }
    }

    while(1){
        cin >> N;
        if (N ==0) break;
        cnt = 0;
        for(int i = N + 1; i <= 2 * N; i++){
            if (!isprime[i]) cnt++;
        }
        cout << cnt << '\n';
    }
}
