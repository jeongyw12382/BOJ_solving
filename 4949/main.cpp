#include <bits/stdc++.h>

using namespace std;

string input;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1){
        stack<char> s;
        getline(cin, input);
        if (input == "."){return 0;}
        bool check = true;
        for(int i = 0; i < input.size(); i++){
            if(input[i] == '(' || input[i] == '['){s.push(input[i]);}
            if(input[i] == ')'){
                if(s.empty() || s.top() != '('){check = false; break;}
                else{s.pop(); continue;}
            }
            if(input[i] == ']'){
                if(s.empty() || s.top() != '['){check = false; continue;}
                else{s.pop(); continue;}
            }
        }
        if (!check || !s.empty()) {cout << "no\n"; continue;}
        cout << "yes\n";
    }
}
