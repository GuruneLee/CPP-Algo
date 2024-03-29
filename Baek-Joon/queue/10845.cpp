// 큐
#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    queue<int> q;
    for (int i = 0; i < n; i++) {
        q.push(i + 1);
    }

    for (int i = 0; q.size() > 1; i++) {
        if (i%2==0) {
            q.pop();
        } else {
            q.push(q.front());
            q.pop();
        }
    }

    cout << q.front() << '\n';
}