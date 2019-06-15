#include <iostream>
#define first(p) (p.first.first)
#define second(p) (p.first.second)
#define third(p) (p.second.first)
#define fourth(p) (p.second.second)
#define MOD 1000000

using namespace std;
typedef pair<pair<long long, long long>, pair<long long, long long>> matrix;
long long N;
const matrix basic_mat = {{1,1},{1,0}};
const matrix idt = {{1,0},{0,1}};

matrix mult(matrix mat1, matrix mat2){
    matrix ret;
    first(ret) = (first(mat1) * first(mat2) + second(mat1) * third(mat2)) % MOD;
    second(ret) = (first(mat1) * second(mat2) + second(mat1) * fourth(mat2)) % MOD;
    third(ret) = (third(mat1) * first(mat2) + fourth(mat1) * third(mat2)) % MOD;
    fourth(ret) = (third(mat1) * second(mat2) + fourth(mat1) * fourth(mat2)) % MOD;
    return ret;
}

matrix fibo(long long N){
    if (N == 0) { return idt; }
    matrix ret;
    matrix half_fibo = fibo(N / 2);
    ret = mult(half_fibo, half_fibo);
    if (N % 2 == 1){ret = mult(ret, basic_mat);}
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cout << second(fibo(N));
}
