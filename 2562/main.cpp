#include <iostream>
#include <algorithm>

using namespace std;

int arr[10];

int main()
{
    for(int i = 0; i < 9; i++){
        cin >> arr[i];
    }

    cout << *max_element(arr, arr + 9) << '\n' << max_element(arr, arr+9) - arr + 1;
}
