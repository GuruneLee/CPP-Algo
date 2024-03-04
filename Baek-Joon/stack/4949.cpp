// 균형잡힌 세상
#include <iostream>
#include <stack>

using namespace std;

bool balanced(string s) {
    stack<char> ss;
    for(char c: s) {
        if (c != '(' && c != '[' && c != ')' && c != ']') {
            continue;
        }

        if (c == '(' || c == '[') {
            ss.push(c);
        } else {
            if (ss.empty()) {
               return false;
            }

            if ((ss.top()=='[' && c==']') || (ss.top()=='(' && c==')')) {
                ss.pop();
            } else {
                return false;
            }
        }
    }
    return ss.empty();
}

int main() {
    // ()[]
    string line;
    getline(cin, line);
    while(line.compare(".") != 0) {
        if (balanced(line)) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
       getline(cin, line);
    }
}