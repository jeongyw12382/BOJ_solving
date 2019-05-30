#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int A[101][101], B[101][101];
int mul[101][101] = {0};
int N, M, K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> A[i][j];
        }
    }

    cin >> M >> K;

    for(int i = 0; i < M; i++){
        for(int j = 0; j < K; j++){
            cin >> B[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            for(int k = 0; k < M; k++){
                mul[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            cout << mul[i][j] << ' ';
        }
        cout << '\n';
    }


}
