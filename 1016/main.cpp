#include <iostream>
using namespace std;

bool square[1000001] = {false};

int main(){

    long long min_val, max_val;
    cin >> min_val >> max_val;

    for(long long i = 2; i * i <= max_val; i++){
        long long start = min_val / (i * i);
        if (start * i * i != min_val) start++;
        for(long long j = start; i*i*j <= max_val; j++){
            square[i*i*j-min_val] = true;
        }
    }
    int count = 0;
    for(int i = 0; i < max_val-min_val+1; i++){
        if(!square[i]) count++;
    }
    cout << count;
    return 0;
}
