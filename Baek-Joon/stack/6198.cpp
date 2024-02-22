// 옥상 정원 꾸미기
// 탑
#include <stack>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, tmp;
    stack<int> s;
    s.push(1000000001);

    long long sum = 0;
    cin >> n;
    while(n--) {
        cin >> tmp;
        while (s.top() <= tmp)
        {
            s.pop();
        }
        sum += s.size()-1;
        s.push(tmp);
    }
    cout << sum;
}