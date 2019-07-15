#include <bits/stdc++.h>

using namespace std;

deque<int> a;
int N, val, T, cnt = 0;

int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++){
        a.push_back(i);
    }
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> val;
        int idx = -1;
        for(auto src = a.begin(); src != a.end(); ++src){
            if (*src == val) {idx = src - a.begin(); break;}
        }
        if(idx < a.size() - idx){
            for(int j = 0; j < idx; j++){
                a.push_back(a.front());
                a.pop_front();
            }
            cnt += idx;
        }
        else{
            for(int j = 0; j < a.size()-idx; j++){
                a.push_front(a.back());
                a.pop_back();
            }
            cnt += a.size()-idx;
        }
        a.pop_front();
    }
    cout << cnt;
}
