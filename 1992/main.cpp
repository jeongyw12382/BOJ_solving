#include <iostream>
#include <cstring>

using namespace std;

int arr[64][64];
char arr_input[65];
char ret[10000];
int N;

string quad_tree(int x, int y, int len){

    if (len == 1){
        return arr[y][x] == 1? "1" : "0";
    }
    bool is_1 = true;
    bool is_0 = true;
    for(int i = y; i < y + len; i++){
        for(int j = x; j < x + len; j++){
            if(arr[i][j] == 1) is_0 = false;
            else is_1 = false;
        }
    }

    if(is_1) return "1";
    if(is_0) return "0";

    string s = "(";
    s += quad_tree(x, y, len/2);
    s += quad_tree(x + len/2, y, len/2);
    s += quad_tree(x, y + len/2, len/2);
    s += quad_tree(x + len/2, y + len/2, len/2);
    s += ")";
    return s;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr_input;
        for(int j = 0; j < N; j++){
            arr[i][j] = arr_input[j] == '1' ? 1 : 0;
        }
    }

    string ret = quad_tree(0, 0, N);
    cout << ret;

}
