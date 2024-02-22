// 탑
#include <stack>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int,int>> s;
    s.push({100000001, 0});

    long long n;
    long long cur;
    cin >> n;
    

    for (long long i = 1; i < n+1; i++) {
        cin >> cur;
        while (!s.empty() && s.top().first < cur)
        {
            s.pop();
        }

        cout << s.top().second << ' ';
        s.push({cur, i});
    }
}