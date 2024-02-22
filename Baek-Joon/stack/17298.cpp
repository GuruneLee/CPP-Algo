// 오큰수
#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    stack<pair<int, int>> s;
    s.push({0, 1000001});

    int tmp;
    int result[1000001];
    for (int i = 1; i <= n; i++)
    {
        result[i] = -1;
        cin >> tmp;
        while (s.top().second < tmp) {
            result[s.top().first] = tmp;
            s.pop();
        }
        s.push({i, tmp});
    }

    for (int i = 1; i <= n; i++)
    {
        cout << result[i] << ' ';
    }
}