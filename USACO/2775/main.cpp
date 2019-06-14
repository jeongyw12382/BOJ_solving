#include <iostream>

using namespace std;

long long arr[16][16];
int N, K, T;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(cin >> T; T > 0; T--){
        cin >> K>> N;
        for(int i = 0; i < N; i++) arr[0][i] = i+1;
        for(int j = 1; j <= K; j++) arr[j][0] = 1;
        for(int j = 1; j <= K; j++){
            for(int i = 0; i < N; i++){
                arr[j][i] = arr[j][i-1] +arr[j-1][i];
            }
        }
        cout << arr[K][N-1] << '\n';
    }

}
