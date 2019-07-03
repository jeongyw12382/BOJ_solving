#include <bits/stdc++.h>

using namespace std;

vector<int> broken;
int M, val, min_cnt = INT_MAX;
string N;

bool check(string num){
    for(int i = 0; i < num.size(); i++){
        for(int j = 0; j < broken.size(); j++){
            if(num[i] == (char)(broken[j] + '0')) return false;
        }
    }
    return true;
}

int main()
{
    cin >> N >> M;
    min_cnt = abs(100 - stoi(N));
    for(int i = 0; i < M; i++) {cin >> val; broken.push_back(val);}
    for(int i = 0; i <= 1000001; i++){
        string s = to_string(i);
        if(check(s)){
            min_cnt = min((int)(s.size()) + abs(stoi(N) - i), min_cnt);
        }
    }
    cout << min_cnt;
}
