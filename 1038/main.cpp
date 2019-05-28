#include <iostream>
#include <queue>

using namespace std;

long long curr = 0;
long long q_front;
long long N;
queue<long long> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    if (N == 0){
        cout << 0;
        return 0;
    }
    for(long long i = 1; i <= 9; i++){
        q.push(i);
    }
    while (!q.empty()){
        q_front = q.front();
        q.pop();
        for(long long i = 0; i < q_front%10; i++){
            q.push(10 * q_front + i);
        }
        if(++curr == N) break;
    }

    if (curr != N){
        cout << -1;
        return 0;
    }

    cout << q_front;
    return 0;
}
