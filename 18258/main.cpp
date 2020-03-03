#include <bits/stdc++.h>

using namespace std;

char input[10];
queue<int> q;
int val,T;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(cin >> T; T > 0; T--){
        cin >> input;
        if (!strcmp(input, "push")){
            cin >> val;
            q.push(val);
        }
        if (!strcmp(input, "front")){
            if (q.empty()){
                cout << -1 << '\n';
                continue;
            }
            cout << q.front() << '\n';
        }
        if (!strcmp(input, "back")){
            if (q.empty()){
                cout << -1 << '\n';
                continue;
            }
            cout << q.back() << '\n';
        }
        if (!strcmp(input, "empty")){
            cout << q.empty() << '\n';
        }
        if (!strcmp(input, "pop")){
            if (q.empty()){
                cout << -1 << '\n';
                continue;
            }
            int top = q.front();
            cout << top << '\n';
            q.pop();
        }
        if(!strcmp(input, "size")){
            cout << q.size() << '\n';
        }



    }

}
