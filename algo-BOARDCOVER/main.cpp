#include <iostream>

using namespace std;

int T, H, W;
char arr[21][21] = {0};
long long cnt;

int count(){

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(cin >> T; T >= 0; T--){
        cin >> H>> W;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                cin >> arr[i][j];
            }
        }
    }
}
