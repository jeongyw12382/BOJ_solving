#include <iostream>

using namespace std;

int N, cnt = 0;

int main()
{
    cin >> N;
    if(N == 0){cnt = 0;}
    while(N != 0){
        cnt+= N/5; N/=5;
    }
    cout << cnt;
}
