#include <iostream>
#include <vector>

using namespace std;

int isCycle(vector<int>& foot, int start) {
    int cnode = -1;
    int cnt = 0;
    while(true) {
        if (cnode == start) {
            return cnt;
        }
        if (cnt > (int)foot.size() || cnt > 1000) {
            return -1;
        }
        
        if (cnode == -1) cnode = start;

        cnode = foot[cnode];
        cnt++; 
    }
    return -1;
}

int main() {
    int N;
    cin >> N;
    vector<int> foot(N, 0);
    for (int i=0; i<N; i++) {
        cin >> foot[i];
        foot[i]+=i;
    }

    int max = 0;
    for (int i=0; i<N; i++) {
        int flag = isCycle(foot, i);
        if (flag > 0) {
            max = max<flag?flag:max;
        }
    }

    cout << max << endl;

    return 0;
}