#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(string a, string b){
    if (a.length() == b.length()){
        return a < b;
    }
    return a.length() < b.length();
}

int N;
string input[20001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input[i];
    }

    sort(input, input + N, cmp);

    cout << input[0] << '\n';
    for(int i = 0; i < N; i++){
        if (i >= 1 && input[i-1] != input[i])
            cout << input[i] << '\n';
    }

}
