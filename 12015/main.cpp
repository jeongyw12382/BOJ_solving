#include <bits/stdc++.h>

using namespace std;

/*
* This problem is finding a longest increasing sequence.
* We only need to consider that if a new point is found,
* and if it is larger than the rightmost value, simply add at last.
* If it is smaller than the rightmost value, do binary-search to modify
* the lower_bound of the vector
*
* Time Complexity O(nlogn)
*/

vector<int> vec;
int N, val;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vec.push_back(INT_MIN);
    for(int i = 0; i < N; i++){
        cin >> val;
        if(vec.back() < val){
            vec.push_back(val);
        } else{
            auto lo = lower_bound(vec.begin(), vec.end(), val);
            *lo = val;
        }
    }
    cout << vec.size() - 1;

}
