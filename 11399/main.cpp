#include <iostream>
#include <algorithm>

using namespace std;

int ATM[1001];
int N, time = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> ATM[i];
    }

    sort(ATM, ATM +N);

    for(int i = 0; i < N; i++){
        time += ATM[i] * (N - i);
    }

    cout << time;

}
