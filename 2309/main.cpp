#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int height[10];
int result[10];
int fin_i, fin_j;
int curr = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0 ; i < 9; i++){
        cin >> height[i];
    }
    int sum_val = accumulate(height, height + 9, 0);

    for(int i = 0; i < 9; i++){
        for(int j = i + 1; j < 9; j++){
            if (sum_val - height[i] - height[j] == 100){
                fin_i = i; fin_j = j;
            }
        }
    }

    for(int i = 0; i < 9; i++){
        if (i != fin_i && i != fin_j){
            result[curr++] = height[i];
        }
    }

    sort(result, result + 7);

    for(int i = 0; i < 7; i++){
        cout << result[i] << '\n';
    }

    return 0;
}

