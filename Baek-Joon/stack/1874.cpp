// 스택 수열
// 스택을 이용한 시물레이션 문제
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cur = 1;
    int input;
    stack<int> num;
    vector<char> result;
    while (n--)
    {
        cin >> input;
        while (cur <= input) {
            num.push(cur);
            result.push_back('+');
            cur++;
        }

        if (num.top() == input) {
            num.pop();
            result.push_back('-');
        } else {
            cout << "NO";
            return 0;
        }
    }

    for(auto c: result) {
        cout << c << '\n';
    }
}