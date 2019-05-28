#include <iostream>

using namespace std;

int result, N;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> result;

    for(int i = 1; i <= result; i++){
        int val = i;
        int decomp_val = val;
        while(val != 0){
            decomp_val += val % 10;
            val /= 10;
        }
        if (result == decomp_val){
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}

