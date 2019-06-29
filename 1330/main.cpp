#include <iostream>

using namespace std;

int A, B;

int main()
{
    cin >> A >> B;
    if (A > B) {cout << '>'; return 0;}
    if (A < B) {cout << '<'; return 0;}
    cout << "==";
    return 0;
}
