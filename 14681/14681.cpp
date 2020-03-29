#include <bits/stdc++.h>

using namespace std;

int x, y;

int main(){

    cin >> x >> y;
    cout << (
        (y > 0) ? 
        (x > 0) ? 1 : 2 : 
        (x > 0) ? 4 : 3
    )
    ;

}