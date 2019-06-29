#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

stack<int> stk;
vector<char> sign;
int n, val = 1, idx = 0;
int arr[1000000];
bool pos = true;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    while(idx != n){
        if(arr[idx] > val){
            sign.push_back('+');
            stk.push(val);
            val++;
            continue;
        }
        else if (arr[idx] == val){ idx++; val++; sign.push_back('+'); sign.push_back('-');}
        else{
            int curr_idx = idx;
            while(curr_idx != n && arr[curr_idx] < val){
                if (stk.top() != arr[curr_idx]){cout << "NO"; return 0;}
                stk.pop();
                curr_idx++;
                sign.push_back('-');
            }
            idx = curr_idx;
        }
    }

    for(int i = 0; i < sign.size(); i++){
        cout << sign[i] << '\n';
    }



}
