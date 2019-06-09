/*
ID: your_id_here
TASK: gift1
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string name[100];
string giver, taker;
int num_process, cost, num;
int arr[100] = {0};

int idx(string input){
    for(int i = 0; i < num_process; i++){
        if (input == name[i]){
            return i;
        }
    }
    return -1;
}

int main()
{
    ofstream fout("gift1.out");
    ifstream fin("gift1.in");
    fin >> num_process;
    for(int i = 0; i < num_process; i++){
        fin >> name[i];
    }
    for(int i = 0; i < num_process; i++){
        fin >> giver;
        int curr_idx = idx(giver);
        fin >> cost >> num;
        if (num != 0){
            arr[curr_idx] -= cost;
            arr[curr_idx] += cost % num;
        }
        for(int j = 0; j < num; j++){
            fin >> taker;
            arr[idx(taker)] += cost / num;
        }
    }

    for(int i = 0; i < num_process; i++){
        fout << name[i] << ' ' << arr[i] << '\n';
    }

}
