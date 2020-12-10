#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;
//없으면 true
bool solution(vector<string> phone_book) {
    bool answer = true;
    //sort(phone_book.begin(), phone_book.end(), sortFunc);
    map<string, int> m;
    for (auto s : phone_book) {
        m[s] = 1;
    }

    for (auto s : phone_book) {
        m[s] = 0;
        string ap = "";
        for (int i=0; i<s.size(); i++) {
            char ts = s[i];
            ap.append(1, ts); //문자를 추가할 때는 개수를 같이 기입해야 함
            if (m[ap] == 1) {
                answer = false;
                return answer;
            }
        }
        m[s] = 1;
    }
    return answer;
}

/*
bool sortFunc(string s1, string s2) {
    return s1.size() < s2.size();
}
*/

int main () {
    vector<string> v = {"123", "1234", "567"};
    cout << solution(v) << endl;
}