#include <iostream>

using namespace std;

int x1, y1, r1, x2, y2, r2, T;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(cin >> T; T > 0; T--){
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int R2 = (r1 + r2) * (r1 + r2);
        int R1 = (r1 - r2) * (r1- r2);
        int euc = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        if (r1 == r2 && x1 == x2 && y1 == y2) {cout << -1 << '\n'; continue;}
        if (euc == R1 || euc == R2){cout << 1 << '\n'; continue;}
        if (euc < R1 || euc > R2){cout << 0 << '\n'; continue;}
        else{cout << 2 << '\n'; continue;}
    }

}
