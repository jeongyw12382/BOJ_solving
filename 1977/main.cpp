#include <iostream>
#include <cmath>

using namespace std;

int N, M;
int sum = 0;
int min_val;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    int L = floor(sqrt(M));
    int K = ceil(sqrt(N));
    if (L * L == M) min_val = M;
    else {
        min_val = (L + 1) * (L + 1);
        L++;
    }
    if (min_val > N) {cout << -1; return 0;}
    for(int i = L; i < K; i++){
        sum += i * i;
    }
    if (K * K == N) sum += N;
    cout << sum << '\n';
    cout << min_val;

}
