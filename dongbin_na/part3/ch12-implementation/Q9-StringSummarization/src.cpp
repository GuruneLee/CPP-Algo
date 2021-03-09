#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.size(); //최대값이 s의 길이여야 함
    for (int gap=1; gap<s.size()/2+1; gap++) {
        string compressed = "";
        string prev = s.substr(0,gap);
        int cnt = 1;
        for (int j=gap; j<s.size(); j+=gap) {
            if (prev == s.substr(j,gap))
                cnt ++;
            else {
                compressed += (cnt>1)? to_string(cnt) + prev : prev;
                prev = s.substr(j, gap);
                cnt = 1;
            }
        }
        compressed += (cnt>1)? to_string(cnt)+prev : prev;
        answer = min(answer, (int)compressed.size());
    }
    return answer;
}

int main() {
    string s = "aabbaccc";
    int answer = 7;

    if (solution(s) == answer) {
        cout << "Correct!" << endl;
    } else {
        cout << "Suck your face;;;" << endl;
    }
    return 0;
}