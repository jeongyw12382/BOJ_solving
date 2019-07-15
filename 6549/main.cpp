#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, S;
int arr[100000], tree[400000];

void update(){
    for(int i = 0; i < N; i++){
        tree[S/2 -1 + i] = i;
    }
    for(int i = S/2-2; i >=0; i--){
        if(tree[2*i + 2] == -1){tree[i] = tree[2*i + 1]; continue;}
        tree[i] = arr[tree[2*i + 2]] > arr[tree[2*i+1]] ? tree[2*i+1] : tree[2*i+2];
    }
}

int seg_tree(int l, int r, int c_l, int c_r, int idx){
    if (c_l > r || c_r < l) return -1;
    if (l <= c_l && c_r <= r) return tree[idx];
    int left_idx = seg_tree(l, r, c_l, (c_l+c_r)/2, 2*idx+1);
    int right_idx = seg_tree(l, r, (c_l+c_r+1)/2, c_r, 2*idx+2);
    if(left_idx == -1) return right_idx;
    if(right_idx == -1) return left_idx;
    return arr[left_idx] < arr[right_idx] ? left_idx : right_idx;
}

int simple_seg_tree(int l, int r){
    return seg_tree(l, r, 0, S/2-1, 0);
}

ll l_rec(int l, int r){
    if (l > r) return 0;
    int idx = simple_seg_tree(l, r);
    ll l_a = l_rec(l, idx-1);
    ll r_a = l_rec(idx+1, r);
    ll max_area = max(l_a, r_a);
    max_area = max(max_area, (r-l+1)*(ll)(arr[idx]));
    return max_area;
}

int main(){

    while(1){
        cin >> N;
        if(N==0) return 0;
        for(int i = 0; i < N; i++) cin >> arr[i];
        for(S = 1; S < 2*N; S *= 2);
        memset(tree, -1, sizeof(tree));
        update();
        cout << l_rec(0, N-1) << endl;
    }

}
