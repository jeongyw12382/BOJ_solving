#include <iostream>

using namespace std;

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = M; i > 0; i /= 10){
        cout << (i % 10) * N << '\n';
    }
    cout << N * M;

}
