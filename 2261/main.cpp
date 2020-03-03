#include <bits/stdc++.h>

using namespace std;

int N, f, s, d = INT_MAX, er = 0;
pair<int, int> vec[100001];

int square(int x){ return x * x;}

struct pair_cmp {
    bool operator() (pair<int, int> a, pair<int, int> b) const{
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
};

int dist(pair<int, int> p1, pair<int, int> p2){
    return square(p1.first-p2.first) + square(p1.second-p2.second);
}

int main(){

    set<pair<int, int>, pair_cmp> st;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> vec[i].first >> vec[i].second;
    }

    sort(vec, vec + N);

    for(int i = 0; i < N; i++){
        for(int j = er; j < i; j++){
            if ((vec[i].first - vec[j].first) * (vec[i].first - vec[j].first) > d){
                st.erase(vec[j]);
                er++;
                continue;
            }
            break;
        }
        int dist_val = (int)sqrt((double)d) + 1;
        pair<int, int> lo = {-100010, vec[i].second - dist_val};
        pair<int, int> hi = {100000, vec[i].second + dist_val};
        auto l = st.lower_bound(lo);
        auto r = st.lower_bound(hi);
        for(auto it = l; it != r; it++){
            d = min(d, dist(vec[i], *it));
        }
        st.insert(vec[i]);
    }

    cout << d;

}
