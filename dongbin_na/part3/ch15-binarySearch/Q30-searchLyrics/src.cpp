#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> w;

bool isMatch(string q, string ww) {
    bool re = true;

    if (q.size() != ww.size()) return false;
    for (int i=0; i<q.size(); i++) {
        if (q[i] == '?') break;
        if (q[i] != ww[i]) {
            re = false;
            break;
        }
    }

    return re;
}

int upper (string q) { //binary search
    int s = 0;
    int e = w.size()-1;
    while(s < e) {
        int m = (s+e)/2;
        if (isMatch(q, w[m])) {
            s = m+1;
        } else {
            if (q.size() > w[m].size()) {
                s = m+1;
            } else {
                e = m-1;
            }
        }
    }  
    
    return s;
}

int lower (string q) { //binary search
    int s = 0;
    int e = w.size()-1;
    while(s < e) {
        int m = (s+e)/2;
        if (isMatch(q, w[m])) {
            e = m-1;
        } else {
            if (q.size() < w[m].size()) {
                e = m-1;
            } else{
                s = m+1;
            }
        }
    }  
    
    return e;
}

bool compare(string a, string b) {
    if (a.size() < b.size()) return true;
    else if (a.size() > b.size()) return false;

    return a<b;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    for (auto q : queries) {
        int t1, t2;
        if (*(q.end()-1) == '?') {
            w = vector<string>(words);
            sort(w.begin(), w.end(), compare);
            t1 = upper(q);
            t2 = lower(q);
        } else {
            w = vector<string>(words);
            for (int i=0; i<w.size(); i++) {
                reverse(w[i].begin(), w[i].end());
            }
            sort(w.begin(), w.end(), compare);
            reverse(q.begin(), q.end());
            t1 = upper(q);
            t2 = lower(q);
        }
        w.clear();
        answer.push_back(t1-t2);
    }

    return answer;
}

int main() {
    vector<string> words = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
    vector<string> queries = {"fro??", "????o", "fr???", "fro???", "pro?"};
    auto t = solution(words, queries);

    return 0;
}