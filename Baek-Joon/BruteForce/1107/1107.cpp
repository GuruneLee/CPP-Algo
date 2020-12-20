#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

bool button[10];

bool check(int num) {
    string sn = to_string(num);
    for (auto c : sn) {
        int tmp = c-48;
        if (!button[tmp]) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    int tmp = M;
    memset(button, true, sizeof(button));
    while(tmp--) {
        int t;
        cin >> t;
        button[t] = false;
    }

    int min = abs(N-100);
    for (int i=0; i<=1000000; i++) {
        if (check(i)) {
            tmp = abs(N-i) + to_string(i).size();
            if (min > tmp) {
                min = tmp;
            }
        }
    }

    cout << min << endl;

}