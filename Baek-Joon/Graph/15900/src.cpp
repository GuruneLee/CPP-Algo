#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> g(N+1, vector<int>());
    // 뭐가 부모인지 안알려줌
    vector<int> visit(N+1, -1); 
    for (int i=0; i<N-1; i++) {
        int a, b;
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // 다 받아서 visit에 저장하면서 leaf까지의 거리를 모두 더하기
    queue<int> q; //depth, node
    q.push(1);
    visit[1] = 0;
    int sum = 0;
    while (!q.empty()) {
        int cn = q.front();
        q.pop();

        bool isLeaf = 0;
        for (int i=0; i<g[cn].size(); i++) {
            int nn = g[cn][i];
            if (visit[nn] != -1) continue;
            visit[nn] = visit[cn] + 1;
            q.push(nn);
            isLeaf = false;
        }

        if (isLeaf) {
            sum += visit[cn];
        }
    }

    //cout << sum << endl;
    if (sum%2 == 0) {
        cout << "No";
    } else {
        cout << "Yes";
    }
    
    return 0;
}