#include <bits/stdc++.h>

using namespace std;

struct c{
    int a;
    int b;
    bool operator<(const c& other){
        return (this->a > other.a);
    }
};

int main(){
    c a = {1, 2};
    c b = {1, 1};
    cout << (a < b);
}