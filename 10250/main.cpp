#include <iostream>

using namespace std;

int N, H, W, T;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(cin >> T; T > 0; T--){
        cin >> H >> W >> N;
        if (N % H != 0)
            cout << 100 * (N % H) + (N / H + 1) << '\n';
        else
            cout << 100 * H + (N / H)<< '\n';
    }
}
