#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string ni) {
    string answer = "";
    for (int i=0; i<ni.size(); i++) {
        int cc = ni[i];
        if ('A'<=cc && cc<='Z') {
            ni[i] = cc-'A'+'a';
            cc = ni[i];
        }
        if (('a'<=cc && cc<='z') || ('0'<=cc && cc<='9') || cc=='-' || cc=='_' || cc=='.') {
            answer += cc;
        }
    }

    bool flag = true;
    while (answer.size() > 1 && flag) {
        flag = false;
        for (int i=1; i<answer.size(); i++) {
            if (answer[i] == '.' && answer[i-1] == '.') {
                answer.erase(answer.begin()+i-1);
                flag = true;
            }
        }
    }

    if (answer[0] == '.') answer.erase(answer.begin());
    if (answer[answer.size()-1] == '.') answer.erase(answer.end()-1);

    if (answer.size()==0) {
        answer += 'a';
    }

    if (answer.size() > 15) {
        int nor = answer.size() - 15;
        while (nor --) {
            answer.erase(answer.begin()+15);
        }
    }
    if (answer[answer.size()-1] == '.') answer.erase(answer.end()-1);

    if (answer.size() <= 2) {
        int noa = 3 - answer.size();
        while (noa --) {
            answer += answer[answer.size()-1];
        }
    }
    
    return answer;
}

int main() {
    string ni = "...!@BaT#*..y.abcdefghijklm";
    cout << solution(ni) << endl;

    return 0;
}