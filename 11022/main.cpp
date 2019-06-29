#include <iostream>

using namespace std;

int T, A, B, i = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(cin >> T; T > 0; T--){
        cin >> A >> B;
        cout << "Case #" << ++i << ": " << A << " + " << B << " = " << A+B << '\n';
    }
    return 0;
}
