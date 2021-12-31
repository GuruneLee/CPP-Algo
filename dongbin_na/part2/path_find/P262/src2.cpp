#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int n,m,c;
vector<pair<int,int>> graph[30001];
vector<int> visit;

int main() {
    cin >> n >> m >> c;
    visit = vector<int>(n+1, 987654321);

    for (int i=1; i<m+1; i++) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b,c});
    }

    priority_queue<pair<int,int>> pq;
    pq.push({0, c});
    visit[c] = 0;

    while(!pq.empty()) {
        int cnode = pq.top().second;
        int ccost = -pq.top().first;
        pq.pop();

        for (auto e : graph[cnode]) {
            int nnode = e.first;
            int ncost = ccost + e.second;
            if (visit[nnode] == 987654321) {
                pq.push({-ncost, nnode});
                visit[nnode] = min(visit[nnode], ncost);
            }
        }
    }

    int cnt = -1;
    int max = -1;
    for (auto cost : visit) {
        if (cost != 987654321) {
            cnt ++;
            max = max<cost?cost:max;
        }
    }

    cout << cnt << ' ' << max << endl;

    return 0;
}