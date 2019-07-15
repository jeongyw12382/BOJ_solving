#include <bits/stdc++.h>

using namespace std;

stack<pair<int, int> > s;
pair<int, int> arr[1000010];
int ret[1000010];

int N, idx = 1;

int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    s.push(arr[0]);
    while(idx != N){
        if(arr[idx-1].first >= arr[idx].first){
            s.push(arr[idx++]);
            continue;
        }
        while(!s.empty() && s.top().first < arr[idx].first){
            ret[s.top().second] = arr[idx].first;
            s.pop();
        }
        s.push(arr[idx++]);
    }

    while(!s.empty()){
        ret[s.top().second] = -1;
        s.pop();
    }

    for(int i = 0; i < N; i++){
        cout << ret[i];
        if (i != N-1) cout << ' ';
    }

}
