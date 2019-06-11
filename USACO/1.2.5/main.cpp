/*
ID: jyw12381
TASK: beads
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool all_w = true, all_r = true, all_b = true;
int N, max_val = -1;
char bead[500];

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");

    ios_base::sync_with_stdio(false);
    fin.tie(NULL);

    fin >> N;
    for(int i = 0; i < N; i++){
        fin >> bead[i];
        if (bead[i] != 'w') all_w = false;
        if (bead[i] != 'r') all_r = false;
        if (bead[i] != 'b') all_b = false;
    }

    if (all_w || all_r || all_b){
        fout << N << '\n';
        return 0;
    }

    for(int i = 0; i < N; i++){
        int left = i == 0 ? N - 1 : i - 1;
        int right = i;
        for(; bead[left] == 'w'; left = (left == 0) ? N-1 : left-1);
        for(; bead[right] == 'w'; right = (right == N-1) ? 0 : right+1);
        char color_left = bead[left], color_right = bead[right];
        for(; bead[left] == color_left || bead[left] == 'w'; left = (left == 0) ? N-1 : left-1);
        for(; bead[right] == color_right || bead[left] == 'w'; right = (right == N-1) ? 0 : right+1);
        int val = (right - left)<= 0 ? right-left+N+1 : right-left + 1;
        cout << right << ' ' << left << '\n';
        max_val = (max_val < val) ? val : max_val;
    }
    fout << max_val << '\n';
    return 0;
}
