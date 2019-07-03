#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, T, i, j, max_val = INT_MIN;
const int init[6] = {0, 1, 1, 1, 2, 2};
vector<int> cases;
ll dp[101];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(cin >> T; T > 0; T--){
        cin >> N;
        cases.push_back(N);
        max_val = max(max_val, N);
    }
    for(i = 0; i < 6; i++) dp[i] = init[i];
    while(i <= max_val){
        for(j = i; j < i + 5; j++){
            dp[j] = dp[j - 5] + dp[j - 1];
        }
        i = j;
    }

    for(int i = 0; i < cases.size(); i++){
        cout << dp[cases[i]] << '\n';
    }

}
