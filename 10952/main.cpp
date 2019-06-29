#include <iostream>

using namespace std;

int A, B;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1){
        cin >> A >> B;
        if (A == B && B == 0) break;
        cout << A + B << '\n';
    }
}
