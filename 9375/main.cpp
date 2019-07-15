#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int T, N;
string type, dummy;
ll val = 1;

int main()
{
    for(cin >> T; T > 0; T--){
        val = 1;
        map<string, int> mp;
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> dummy >> type;
            if (mp.find(type) == mp.end()){
                mp[type] = 0;
            }
            mp[type] += 1;
        }
        for(auto a = mp.begin(); a != mp.end(); ++a){
            val *= (a->second + 1);
        }
        cout << val-1 << '\n';
    }

}
