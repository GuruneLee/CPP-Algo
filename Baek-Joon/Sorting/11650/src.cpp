#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<pair<int,int>> q;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        q.push({-a,-b});
    }

    while (!q.empty()) {
        printf("%d %d\n", -q.top().first, -q.top().second);
        q.pop();
    }

    return 0;
}