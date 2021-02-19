#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int V;
    int E;
    cin >> V >> E;
    vector<int> visit(V+1);
    vector<vector<int>> el(V+1, vector<int>());
    for (int i=0; i<E; i++) {
        int a,b;
        cin >> a >> b;
        el[a].push_back(b);
        el[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    int cnt = 0;
    visit[1] = 1;
    
    while (!q.empty()) {
        int cv = q.front();
        q.pop();
        
        for (int i=0; i<el[cv].size(); i++) {
            int nv = el[cv][i];
            if (visit[nv] == 1) continue;
            q.push(nv);
            cnt ++;
            visit[nv] = 1;
        }
    }

    cout << cnt;
    return 0;
}