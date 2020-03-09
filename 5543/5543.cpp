#include <bits/stdc++.h>

using namespace std;

int bg1, bg2, bg3;
int drink1, drink2;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> bg1 >> bg2 >> bg3;
    cin >> drink1 >> drink2;

    cout << min(drink1, drink2) + min(bg1, min(bg2, bg3)) - 50; 

}