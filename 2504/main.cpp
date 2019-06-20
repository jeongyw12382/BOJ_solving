#include <iostream>
#include <string>
#include <stack>

using namespace std;

string input;
long long curr_sum = 0, curr_prod = 1, val;
stack<char> char_stack;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;
    input = ' ' + input;
    for(int i = 1; i <= input.size(); i++){
        switch(input[i]){
        case '(': case '[':
            val = input[i] == '(' ? 2 : 3;
            curr_prod *= val; char_stack.push(input[i]); break;
        case ')': case ']':
            char other = input[i] == ')' ? '(' : '[';
            val = input[i] == ')' ? 2 : 3;
            if (input[i-1] == other) curr_sum += curr_prod;
            if (char_stack.empty()) {cout << 0; return 0;}
            if (char_stack.top() == other) {char_stack.pop();}
            curr_prod /= val; break;
        }
    }
    if (!char_stack.empty()) {cout << 0; return 0;}
    cout << curr_sum;
}
