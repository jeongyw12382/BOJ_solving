#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> arr[100000];
int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + N);
    for(int i = 0; i < N; i++){
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }

}
