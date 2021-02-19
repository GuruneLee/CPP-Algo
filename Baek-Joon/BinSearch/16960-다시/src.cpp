#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n+1, vector<int>());
    for (int i=1; i<n+1; i++) {
        int t;
        scanf("%d", &t);
        while(t--) {
            int x;
            scanf("%d", &x);
            v[i].push_back(x);
        }
    }

    for (int no=1; no<n+1; no++) {
        vector<bool> visit(m+1, false);
        //no는 안껴줄거임
        for (int i=1; i<n+1; i++) {
            if (i == no) continue;
            for (int j=0; j<v[i].size(); j++) {
                visit[v[i][j]] = true;
            }
        }

        bool flag = true;
        for (int i=1; i<visit.size(); i++) {
            if (!visit[i]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;

    return 0;
}