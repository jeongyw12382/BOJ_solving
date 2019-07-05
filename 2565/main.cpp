#include <bits/stdc++.h>

using namespace std;

int val, N, idx, ret = 1;
vector<pair<int, int> > arr;
vector<int> dp;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> idx >> val;
        arr.push_back({idx, val});
        dp.push_back(1);
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < arr.size(); i++){
        int max_val = 1;
        for(int j = 0; j < i; j++){
            if (arr[i].second > arr[j].second) max_val = max(max_val, dp[j] + 1);
        }
        dp[i] = max_val;
        ret = max(ret, max_val);
    }

    cout << N - ret;

}