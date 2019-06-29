#include <bits/stdc++.h>
#include <vector>

using namespace std;

int cnt = 0, N;
vector<pair<int ,int> > vec;

void hanoi(int n, int from, int to, int other){
    if(n == 1) {vec.push_back({from, to}); cnt++; return;}
    hanoi(n-1, from, other, to);
    hanoi(1, from, to, other);
    hanoi(n-1, other, to, from);
}

int main()
{
    cin >> N;
    hanoi(N, 1, 3, 2);
    cout << cnt << '\n';
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i].first << ' ' << vec[i].second << '\n';
    }
    return 0;
}
