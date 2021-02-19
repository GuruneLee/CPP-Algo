#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int l,n;
queue<int> s;
priority_queue<pair<int,int>> q; //lucky, num

int com(int n, int r){
    if (n < r) {
        return 0;
    }
    if(n == r || r == 0) 
        return 1; 
    else 
        return com(n - 1, r - 1) + com(n - 1, r);
}

int Cal (int l, int r, int i) {
    int whole = com(r-l-1, 2);
    if (whole == 0) {
        return 0;
    }
    int left = com(i-l-1, 2);
    int right = com(r-i-1, 2);
    
    return whole - left - right;
}

int main() {
    cin >> l;
    int max_num = 0;
    for (int i=0; i<l; i++) {
        //cin >> s[i];
        int a;
        cin >> a;
        max_num = a;
        s.push(a);
    }

    cin >> n;

    int l=0, r=s.front();
    for (int i=1; i<101; i++) {
        if (i <= max_num){
            if (i == r) {
                q.push({0, -i});
                l = s.front();
                s.pop();
                r = s.front();
            } 

            if (l < i && i < r) {
                int tmp = Cal(l,r,i);
                q.push({-tmp, -i});
            } 
        } else {
            q.push({-987654321, -i});
        }
    }

    while (n--) {
        cout << -q.top().second << " ";
        q.pop();
    }

    return 0;
}