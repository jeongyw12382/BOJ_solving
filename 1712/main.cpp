#include <iostream>

using namespace std;

int A, B, C;

int main()
{
    cin >> A >> B >> C;
    if (B >= C) {cout << -1; return 0;}
    cout << A / (C - B) + 1;

}
