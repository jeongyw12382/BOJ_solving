#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int arr[101];
int N, gcd_val;
vector<int> arr;

int gcd(int a, int b){
    if (max(a,b) % min(a,b) == 0) return min(a,b);
    return gcd(max(a,b) % min(a,b), min(a,b));
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    gcd_val = arr[1] - arr[0];
    for(int i = 0; i < N; i++){
        int diff = abs(arr[(i + 1) % N] - arr[i]);
        gcd_val = gcd(gcd_val, diff);
    }
    for (int i = 2; i <= ceil(sqrt(gcd_val)); i++){
        if(gcd_val % i == 0)
            cout << i << ' ';
    }


}
