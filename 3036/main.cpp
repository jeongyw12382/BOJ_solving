#include <iostream>


using namespace std;

int N, arr[101];

int gcd(int a, int b){
    return a % b ? gcd(b, a%b): b;
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    for(int i = 1; i < N; i++){
        cout << (arr[0] / gcd(arr[0], arr[i])) << '/' << (arr[i] / gcd(arr[0], arr[i])) << '\n';
    }
}
