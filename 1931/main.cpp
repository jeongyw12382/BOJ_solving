#include <iostream>
#include <algorithm>

using namespace std;

struct job {
    int start_time;
    int end_time;
};

int N, curr = 0, cnt = 0;
job arr[100001];

bool cmp (const job& a, const job& b){
    if (a.end_time == b.end_time){
        return a.start_time < b.start_time;
    }
    return a.end_time < b.end_time;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i].start_time >> arr[i].end_time;
    }

    sort(arr, arr+N, cmp);

    for(int i = 0; i < N; i++){
        if (curr <= arr[i].start_time){
            curr = arr[i].end_time;
            cnt++;
        }
    }

    cout << cnt;

}
