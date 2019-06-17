#include <iostream>
#include <cmath>
#define MAX pow(2, 31)

using namespace std;

long long cnt[1000000];
long long i = 0, x, y;
int T;

int main()
{
    while(1){
        cnt[i] = (i/2) * (i/2 + 1);
        cnt[i + 1] = (i/2 + 1) * (i/2 + 1);
        if(cnt[i] > MAX || cnt[i+1] > MAX) {break;}
        i = i + 2;
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(cin >> T; T > 0; T--){
        i = 0;
        cin >> x >> y;
        long long t = y - x;
        while(t != 0){
            if(cnt[i] < t && cnt[i+1] >= t){i = i + 1; break;}
            i++;
        }
        cout << i << '\n';
    }


}
