#include <bits/stdc++.h>

using namespace std;

vector<tuple<int, int, string> > vec;
int N, age;
string name;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> age >> name; 
        vec.push_back(make_tuple(age, i, name));
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < N; i++){
        int x, y;
        string z;
        tie(x, y, z) = vec[i];
        cout << x << ' ' << z << '\n';
    }

}
