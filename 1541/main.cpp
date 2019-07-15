#include <bits/stdc++.h>

using namespace std;

string input;
vector<int> num_vec;
vector<char> oper;
int num = 0, tot_val = 0, idx;

int main()
{
    cin >> input;
    for(int i = 0; i < input.size(); i++){
        if(input[i] == '+' || input[i] == '-') {
            oper.push_back(input[i]);
            num_vec.push_back(num);
            num = 0;
            continue;
        }
        num *= 10;
        num += input[i] - '0';
    }
    num_vec.push_back(num);
    tot_val += num_vec[0];
    if(oper.size() == 0){
        cout << tot_val; return 0;
    }
    for(idx = 0; oper[idx] != '-' && idx < oper.size(); idx++){
        tot_val += num_vec[idx+1];
    }
    for(int j = idx + 1 ; j < num_vec.size(); j++){
        tot_val -= num_vec[j];
    }

    cout << tot_val;

}
