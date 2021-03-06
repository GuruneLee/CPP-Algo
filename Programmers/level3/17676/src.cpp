#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

//스트링 문제는 c++로 풀면 안된다는 사실을 알려주는 문제
vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

int stoMS(string sss) {
    auto tmp = split(sss, '.');
    int ms = stoi(tmp[0])*1000;
    ms += stoi(tmp[1]);
    return ms;
}

int toMS(string dt) {
    auto datetime = split(dt, ':');
    int h = stoi(datetime[0]);
    int m = stoi(datetime[1]);
    int ms = stoMS(datetime[2]);
    
    return (h*60*60 + m*60)*1000 + ms;
}

int whichS(int ms) {
    return ms/1000;
}

int solution(vector<string> lines) {
    int answer = 0;
    //시간을 모두 ms로 바꿔서 시작시간, 끝시간으로 저장
    vector<pair<int,int>> time;
    for (auto s : lines) {
        auto tmp = split(s, ' ');
        string datetime = tmp[1];
        string sstime = tmp[2];
        int stime = stof(sstime.substr(0, sstime.size()-1))*1000;

        int end = toMS(datetime);
        int begin = end - stime + 1;

        time.push_back({begin, end});
    }

    int n = time.size();
    int max = -1;
    // 각 시간대에 들어맞는 모든 구간을 돌며 겹쳐져있는 최대 값 찾기
    for (int p=0; p<n; p++){
        // p번째 시간대의 처음~끝
        for (int i=time[p].first; i<=time[p].second; i++) {
            int rb = i;
            int re = i+1000;
            int cnt = 0;
            for (auto t : time) {
                if (t.second >= rb && t.first < re) {
                    cnt ++;
                }
            }
            max = max<cnt?cnt:max;
        }
    }
    answer = max;
    
    

    return answer;
}

int main() {
    vector<string> lines = {"2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s", "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s", "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s", "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s", "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s"};
    int answer = solution(lines);
    cout << answer;
    return 0;
}