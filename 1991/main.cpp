#include <iostream>

using namespace std;

int tree[100][2] = {0};
int N;
char a,b,c;
int left(int i){ return tree[i][0]; }
int right(int i) { return tree[i][1]; }

void preorder(int i){

    if (i == -1) return;
    cout << char(i + 'A');
    preorder(left(i));
    preorder(right(i));
    return;

}

void inorder(int i){

    if(i == -1){return;}
    inorder(left(i));
    cout << char(i + 'A');
    inorder(right(i));
    return;

}

void postorder(int i){

    if(i == -1){return;}
    postorder(left(i));
    postorder(right(i));
    cout << char(i + 'A');
    return;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b >> c;
        if (b != '.') tree[a - 'A'][0] = b-'A';
        else tree[a - 'A'][0] = -1;
        if (c != '.') tree[a - 'A'][1] = c-'A';
        else tree[a - 'A'][1] = -1;
    }
    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    return 0;

}
