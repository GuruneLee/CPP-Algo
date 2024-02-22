#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, call, sum=0;
    stack<int> st;
    cin >> k;
    while (k--) {
        cin >> call;
        if (call == 0) {
            sum -= st.top();
            st.pop();
        } else {
            sum += call;
            st.push(call);
        }
    }

    cout << sum;
}