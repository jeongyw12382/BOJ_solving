#include <bits/stdc++.h>

using namespace std;

int increasing[1000], decreasing[1000], arr[1000], N, ret = INT_MIN;

int main(){

    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    ret = 1;
    increasing[0] = 1;
    decreasing[0] = 1;
    for(int i = 1; i < N; i++){
        int max_val_inc = 1;
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]) max_val_inc = max(max_val_inc, increasing[j] + 1);
        }
        increasing[i] = max_val_inc;
    }

    reverse(arr, arr + N);

    for(int i = 1; i < N; i++){
        int max_val_dec = 1;
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]) max_val_dec = max(max_val_dec, decreasing[j] + 1);
        }
        decreasing[i] = max_val_dec;
    }

    for(int i = 0; i < N; i++){
        ret = max(ret, increasing[i] + decreasing[N - i - 1] - 1);
    }

    cout << ret;

}