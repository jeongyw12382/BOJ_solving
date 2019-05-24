#include <stdio.h>

using namespace std;

int arr[10001] = {0, };
int N, num;

int main(){

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d", &num);
        arr[num]++;
    }

    for(int i = 1; i <= 10000; i++){
        for(int j = 0; j < arr[i]; j++){
            printf("%d\n", i);
        }
    }

}
