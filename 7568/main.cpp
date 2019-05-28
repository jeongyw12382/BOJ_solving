#include <iostream>

using namespace std;

int N;
int x, y;

pair<int, int> arr[51];
int cnt_arr[51];

auto cmp = [](const pair<int, int> &x, const pair<int, int> &y) -> bool {
    return x.first < y.first && x.second < y.second;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    for(int i = 0; i < N; i++){
        int cnt = 0;
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            if(cmp(arr[i], arr[j])) cnt++;
        }
        cnt_arr[i] = cnt;
    }

    for(int i = 0; i < N; i++){
        cout << cnt_arr[i] + 1 << ' ';
    }

}
