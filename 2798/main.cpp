#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll arr[100], M, N, max_val = LLONG_MIN;

int main(){
    cin >> N >> M;
    for(int i = 0; i < N ; i++) cin >> arr[i];
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            for(int k = j + 1; k < N; k++){
                ll sum_val = arr[i] + arr[j] + arr[k];
                if(sum_val <= M) max_val = max(max_val, sum_val);
            }
        }
    }
    cout << max_val;

}