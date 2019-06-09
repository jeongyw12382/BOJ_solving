#include <iostream>
#include <algorithm>

using namespace std;

int arr[100];
long long N;
int i = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    while(N != 0){
        arr[i] = N % 10;
        N = N / 10;
        i++;
    }

    sort(arr, arr + i, greater<int>());

    for(int j = 0; j < i; j++){
        cout << arr[j];
    }

}
