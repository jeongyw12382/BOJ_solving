#include <bits/stdc++.h>
#define rep(N, i) for(int (i)= 0; (i) < (N); (i)++)

using namespace std;

char chess[50][50];
int N, M, min_cnt = INT_MAX;

int main()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> chess[i][j];
        }
    }

    for(int i = 0; i <= N - 8; i++){
        for(int j = 0; j <= M - 8; j++){
            int cnt1 = 0, cnt2 = 0;
            for(int k = 0; k < 8; k++){
                for(int l = 0; l < 8; l++){
                    if(chess[k + i][l + j] == ((k + l + i + j)%2 == 1 ? 'B' : 'W')) cnt1++;
                    if(chess[k + i][l + j] == ((k + l + i + j)%2 == 0 ? 'B' : 'W')) cnt2++;
                }
            }
            min_cnt = min(min_cnt, min(cnt1, cnt2));
        }
    }
    cout << min_cnt;

}
