#include <iostream>
#include <algorithm>

using namespace std;

int a;
int cnt[10] = {0};

int main()
{
    cin >> a;
    if (a == 0) {cout << 1; return 0;}
    while (a != 0){
        int b = a % 10;
        cnt[b]++;
        a = a / 10;
    }
    cnt[6] += cnt[9];
    cnt[6]++;
    cnt[6] /= 2;

    cout << *max_element(cnt, cnt + 9);

}
