#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int max_day = 0;
    vector<priority_queue<int>> v(1001, priority_queue<int>());
    priority_queue<int> q;

    for (int i=0; i<N; i++) {
        int d,w;
        cin >> d >> w;
        v[d].push(w);
        max_day = max(d,max_day);
    }

    int sum = 0;
    int day = max_day;
    while(day > 0) {
        for (int i=max_day; i>=day; i--) { //i일에
            while(!v[i].empty()) {
                q.push(v[i].top());
                v[i].pop();
            }
        }
        if (!q.empty()) {
            sum += q.top();
            q.pop();
        }
        day --;
    }

    cout << sum << endl;
    return 0;
}