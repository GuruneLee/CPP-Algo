// 회전하는 큐
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int need[51];
int findIndex(deque<int> &arr, int val) {
    int idx = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i]==val) {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;

    deque<int> dq;
    for (int i = 0; i < n; i++) {
        dq.push_back(i + 1);
    }
    for (int i = 0; i < m;i++) {
        cin >> need[i];
    }

    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        int pos = findIndex(dq, need[i]);
        while (dq.front() != need[i]){
            if (pos < dq.size()-pos) {// 왼쪽
                int tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
            }
            else
            { // 오른쪽
                int tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp);
            }
            cnt++;
        }
        dq.pop_front();
    }

    cout << cnt;
}

// 0 1 2 3
// 2 >= 4-2=2 오
// 1 < 4-1=3 왼

// 0 1 2 3 4
// 2 < 5-2=3 왼