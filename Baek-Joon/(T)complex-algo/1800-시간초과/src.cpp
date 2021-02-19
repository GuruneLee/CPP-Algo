#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N, P, K;

vector<int> s;
vector<bool> visit(1001, false);

int res = 987654321;
vector<vector<int>> graph(1001, vector<int>(1001));

void dfs(int v, int e) {
    visit[v] = true;
    s.push_back(v);

    if (v == e) {
        //목적지 찾았다!!
        //s에 있는거 다 꺼내서 더하면 돼 ㅇㅇ
        vector<int> cost;
        for (int i=1; i<s.size(); i++) {
            cost.push_back(graph[s[i-1]][s[i]]);
        }
        sort(cost.begin(), cost.end(), greater<>());
        res = res>cost[K]?cost[K]:res;
        s.pop_back();
        return;
    }

    for (int i=1; i<=N; i++) {
        if (graph[v][i]!=0 && !visit[i]) {
            dfs(i, e);
            visit[i] = false;
        }
    }

    s.pop_back();
}

int main() {
    cin >> N >> P >> K;
    for (int i=0; i<P; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }

    dfs(1,N);

    if (res == 987654321)
        cout << -1;
    else
        cout << res;
    return 0;
}