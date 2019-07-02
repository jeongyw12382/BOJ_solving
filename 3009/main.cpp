#include <iostream>

using namespace std;

int x1, x2, x3, y1, y2, y3;

int main()
{
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int x = (x1 == x2) ? x3 : (x2 == x3) ? x1 : x2;
    int y = (y1 == y2) ? y3 : (y2 == y3) ? y1 : y2;
    cout << x << ' ' << y;

}
