#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[101], curr_max = 0;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            for(int k = j+1; k < N; k++){
                if(arr[i] + arr[j] + arr[k] <= M){
                    curr_max = max(curr_max, arr[i] + arr[j] + arr[k]);
                }
            }
        }
    }

    cout << curr_max;

}
