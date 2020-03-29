#include <bits/stdc++.h>

using namespace std;

vector<int> curr_set;

int score[21][21] = {0}, N, min_val = INT_MAX;

int scoring(vector<int> vec){
    int score_vec = 0;
    for(int i = 0; i < vec.size(); i++){
        for(int j = 0; j < vec.size(); j++){
            score_vec += score[vec[i]][vec[j]];
        }
    }
    return score_vec;
}

int team_score_diff(){
    vector<int> oppose_set;

    for(int i = 0; i < N; i++){
        bool pt = binary_search(curr_set.begin(), curr_set.end(), i);
        if(!pt) oppose_set.push_back(i);
    }

    int score1 = scoring(curr_set);
    int score2 = scoring(oppose_set);
    
    return curr_set.size() == oppose_set.size() ? abs(score1 - score2) : INT_MAX;
}

void bt_rec(int curr){

    if (curr == N){
        min_val = min(min_val, team_score_diff());
        return;
    }

    for(int i = curr+1; i <= N; i++){
        if (i == N) {
            bt_rec(i);
            continue;
        }
        curr_set.push_back(i);
        bt_rec(i);
        curr_set.pop_back();
    }

}

int main(){

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> score[i][j];
        }
    }

    bt_rec(-1);
    cout << min_val;

}