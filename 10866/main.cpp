#include <iostream>
#include <deque>

using namespace std;

string input;
int num_inst, val;
deque<int> deq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(cin >> num_inst; num_inst > 0; num_inst--){
        cin >> input;
        if(input == "push_front"){
            cin >> val;
            deq.push_front(val);
        }
        else if(input == "push_back"){
            cin >> val;
            deq.push_back(val);
        }
        else if(input == "pop_front"){
            if(deq.empty()) {cout << -1 << '\n'; continue;}
            cout << deq.front() << '\n';
            deq.pop_front();
        }
        else if(input == "pop_back"){
            if(deq.empty()) {cout << -1 << '\n'; continue;}
            cout << deq.back() << '\n';
            deq.pop_back();
        }
        else if(input == "size"){
            cout << deq.size() << '\n';
        }
        else if(input == "empty"){
            cout << deq.empty() << '\n';
        }
        else if(input == "front"){
            if(deq.empty()) {cout << -1 << '\n'; continue;}
            cout << deq.front() << '\n';
        }
        else{
            if(deq.empty()) {cout << -1 << '\n'; continue;}
            cout << deq.back() << '\n';
        }
    }
}
