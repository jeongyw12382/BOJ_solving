#include <bits/stdc++.h>

using namespace std;

int main(){

    string input; 
    
    ios_base::sync_with_stdio(false);
    
    cin.tie(0);
    cout.tie(0);

    getline(cin, input);
    
    int len = input.length();
    int cnt = 0;

    if (input[len-1] == ' ')
        cnt--;
    if (input[0] == ' ')
        cnt--;

    for(int i = 0; i < len; i++){
        if(input[i] == ' ')
            cnt++;
    }

    cout << cnt + 1;

}