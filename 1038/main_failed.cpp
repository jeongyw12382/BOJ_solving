#include <iostream>

using namespace std;

int curr = 0;
int i = 0;
int N;

bool is_decrease(int val){

    if (val/ 10 == 0) return true;

    while(val/10 != 0){
        if (val % 10 >= (val/10)%10) return false;
        val /= 10;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    while(curr != N){
        ++i;
        if(is_decrease(i)) curr++;
    }

    cout << i;

}
