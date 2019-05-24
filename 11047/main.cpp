#include <iostream>

using namespace std;

int N;
long long K, cnt = 0;
int cost[11];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    for(int i = 0; i < N; i++){
        cin >> cost[i];
    }

    for(int i = N-1; i >= 0; i--){
        if(cost[i] <= K){
            cnt += K / cost[i];
            K = K % cost[i];
        }
    }
    cout << cnt;
}
