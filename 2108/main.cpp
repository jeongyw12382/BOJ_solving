#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int arr[500001], N;
int cnt[8002] = {0};
double sum = 0.0;
bool first = false, second = false;
int max_val = 0;
int mode = 0, curr_i = -9999;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr + N);

    for(int i = 0; i < N; i++){
        sum += arr[i];
    }
    sum /= N;
    cout << round(sum) << '\n';
    cout << arr[N/2] << '\n';

    for(int i = 0; i < N; i++) ++cnt[arr[i]+4000];
    max_val = *max_element(cnt, cnt + 8002);
    for(int i = 0; i < 8002; i++){
        if (first && max_val == cnt[i]){
            curr_i = i;
            break;
        }
        if (!first && max_val == cnt[i]){
            first = true;
            curr_i = i;
        }
    }

    cout << curr_i - 4000 << '\n';

    cout << arr[N-1] - arr[0] << '\n';
}
