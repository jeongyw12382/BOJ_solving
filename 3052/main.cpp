#include<bits/stdc++.h>

using namespace std;

int arr[10];
set<int> s;

int main()
{
    for(int i = 0; i < 10; i++){
        cin >> arr[i];
        s.insert(arr[i] % 42);
    }
    cout << s.size();
}
