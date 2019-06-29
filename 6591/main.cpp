#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
using ll = long long;

int N, K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1){
        cin >> N >> K;
        if(!N && !K){break;}
        K = min(K, N - K);
        ll result = 1;
        for(int i = 1; i <= K; i++){
            result *= (N - i + 1);
            result /= i;
        }
        cout << result << '\n';
    }
    return 0;

}
