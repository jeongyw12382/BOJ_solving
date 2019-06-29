#include <iostream>

using namespace std;

int N;

int main()
{
    cin >> N;
    cout << (N % 400 == 0 ? 1 : (N % 100 == 0 ? 0 : (N % 4 == 0 ? 1 : 0)));
}
