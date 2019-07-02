#include <iostream>

using namespace std;

int x, y, z;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1){
        cin >> x >> y >> z;
        if (x == 0 && y == 0 && z == 0) return 0;
        if (x*x+y*y==z*z || x*x +z*z==y*y || y*y+z*z==x*x){cout << "right\n"; continue;}
        cout << "wrong\n";
    }
}
