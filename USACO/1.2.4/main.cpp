/*
ID: jyw12381
TASK: friday
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int N;
const int date[12] = {31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31
};
int cnt[7] = {0};
int curr_month = 11, curr_year = 1899, curr_day = 2;

bool isleap(){
    if (curr_year % 400 == 0) return true;
    if (curr_year % 100 == 0) return false;
    if (curr_year % 4 == 0) return true;
    return false;
}

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");

    fin.tie(NULL);
    ios_base::sync_with_stdio(false);

    fin >> N;
    for(int i = 0; i < 12* N; i++){
        int date_add = (isleap() && curr_month == 1) ? 29 : date[curr_month];
        curr_day = (curr_day + date_add) % 7;
        curr_month = (curr_month + 1) % 12;
        curr_year = curr_month == 0 ? curr_year + 1 : curr_year;
        cnt[curr_day]++;
    }

    for(int i = 5; i != 4 ; i = (i + 1) % 7){
        fout << cnt[i] << ' ';
    }
    fout << cnt[4] << '\n';


}
