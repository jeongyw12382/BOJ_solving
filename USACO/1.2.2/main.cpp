/*
ID: your_id_here
TASK: ride
LANG: C++14
*/

#include <iostream>
#include <fstream>

using namespace std;

char string1[7], string2[7];
long long val1 = 1, val2 = 1;

int main()
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");

    fin.tie(NULL);
    ios_base::sync_with_stdio(false);

    fin >> string1 >> string2;
    for(int i = 0; string1[i] != '\0'; i++){
        val1 *= string1[i] - 'A' + 1;
        val1 %= 47;
    }
    for(int i = 0; string2[i] != '\0'; i++){
        val2 *= string2[i] - 'A' + 1;
        val2 %= 47;
    }
    if (val1 == val2){
        fout << "GO\n";
    }
    else{
        fout << "STAY\n";
    }


}
