#include <iostream>

using namespace std;

int arr[20][20], N, K;


int main()
{
    cin >> N >> K;
    arr[0][0] = 1;
    for(int i = 1; i <= N; i++){
        arr[i][0] = 1;
        for(int j = 1; j <= i; j++){
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
    }
    cout << arr[N][K];
}
