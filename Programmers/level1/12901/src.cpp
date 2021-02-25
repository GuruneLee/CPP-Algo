#include <string>
#include <vector>

using namespace std;

string date[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
string solution(int a, int b) {
    string answer = "";
    int gap = 0;
    if (a == 1) {
        gap += b-1; //1월
    } else {
        gap += b+30; //1월+막월
    }

    for (int i=2; i<a; i++) {
        if (i==2) {
            gap += 29;
        }
        if (i==3 || i==5 || i==7 || i==8 || i==10) {
            gap += 31;
        }
        if (i==4 || i==6 || i==9 || i==11) {
            gap += 30;
        }
    }

    gap %= 7;
    answer += date[gap];

    return answer;
}

int main() {
    int a = 5, b = 24;
    auto tmp = solution(a,b);
    return 0;
}