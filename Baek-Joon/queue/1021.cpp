// 회전하는 큐
#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    deque<int> needs;
    int tmp;
    int cur[51] = {};
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        needs.push_back(tmp);
        cur[tmp] = tmp;
    }

    deque<int> dq;
    for (int i = 0; i < n; i++) {
        dq.push_back(i + 1);
    }

    int cnt = 0;
    while (!needs.empty()) {
        int dest = needs.front();
        if (dest == dq.front()) { //
            needs.pop_front();
            dq.pop_front();
        } else if (isLeft(cur[dest], dq.size())) {

        }
    }
}

bool isLeft(int idx, int size) {
    return idx < size/2;
}

// 1 2 3 4 5 6 7 8 9 10
//   1     3       2   