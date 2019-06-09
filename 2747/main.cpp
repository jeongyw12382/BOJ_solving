#include <iostream>

using namespace std;
int N;
long long arr[100]= {0,1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    if (N <= 1){
        cout << arr[N];
        return 0;
    }

    for(int i = 2; i <= N; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }

    cout << arr[N];
    return 0;

}
