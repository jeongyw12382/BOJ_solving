#include <iostream>
#include <algorithm>

using namespace std;

int T, N, M, x, y;

int gcd(int a, int b){
    if (max(a,b) % min(a,b) == 0) return min(a,b);
    else return gcd(min(a,b), max(a,b) % min(a,b));
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(cin >> T; T > 0; T--){
        cin >> M >> N >> x >> y;
        int cnt_val = 0;
        int gcd_val = gcd(M, N);
        if (x % gcd_val != y % gcd_val){
            cout << -1 << '\n'; continue;
        }

        for(int i = 0; x + i * M <= lcm(M, N); i++){
            cnt_val = x + i * M - N * ((x + i * M) / N);
            if (y == cnt_val || (N == y && cnt_val == 0)){
                cnt_val = x +i *M;
                break;
            }
        }
        cout << cnt_val << '\n';
    }
}
