#include <bits/stdc++.h>

using namespace std;

int N, curr = 665, curr_cnt = 0;

bool extinct(int num){
    while(num != 0){
        if(num % 1000 == 666){return true;}
        num /= 10;
    }
    return false;
}

int main()
{
    cin >> N;
    while(curr_cnt != N){
        if(extinct(curr++)){curr_cnt++;}
    }
    cout << curr - 1;
}
