#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<int> one = {1,2,3,4,5};
vector<int> two = {2,1,2,3,2,4,2,5};
vector<int> thr = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int count[3] = {0,0,0};
    for (int i=0; i<answers.size(); i++) {
        int on = i%one.size();
        int tw = i%two.size();
        int th = i%thr.size();
        
        if (answers[i] == one[on]) count[0]+=1;
        if (answers[i] == two[tw]) count[1]+=1;
        if (answers[i] == thr[th]) count[2]+=1;
    }

    if (count[0] == count[1]) {
        if (count[0] == count[2]) {
            answer = vector<int>{1,2,3};
        } else if (count[0] < count[2]) {
            answer = vector<int>{3};
        } else if (count[0] > count[2]) {
            answer = vector<int>{1,2};
        }
    } else if (count[0] > count[1]) {
        if (count[0] == count[2]) {
            answer = vector<int>{1,3};
        } else if (count[0] < count[2]) {
            answer = vector<int>{3};
        } else if (count[0] > count[2]) {
            answer = vector<int>{1};
        }
    } else if (count[1] > count[0]) {
        if (count[1] == count[2]) {
            answer = vector<int>{2,3};
        } else if (count[1] < count[2]) {
            answer = vector<int>{3};
        } else if (count[1] > count[2]) {
            answer = vector<int>{2};
        }
    }

    return answer;
}

int main() {
    vector<int> input = {1};
    auto tmp = solution(input);
    return 0;
}