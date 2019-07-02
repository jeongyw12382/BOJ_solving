#include <bits/stdc++.h>

using namespace std;

int N, M, val, broken[10] = {0};
int cnt[500000] = {0};

pair<bool, int> check(int k){
    int cnt = 0;
    while(k != 0){
        for(int i = 0 ; i < 10; i++){
            if (broken[k % 10]) return {false, INT_MAX};
        }
        k /= 10;
        cnt++;
    }
    return {true, cnt};
}

int main()
{
    cin >> N >> M;
    for(int i = 0; i< M; i++){
        cin >> val;
        broken[val] = 1;
    }
    for(int i = 0; i<500000; i++){
        auto check_curr = check(i + 1);
        if(!check_curr.first) cnt
    }

}
