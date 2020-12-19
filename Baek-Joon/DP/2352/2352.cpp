#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> l;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int here;
        scanf("%d", &here);
        if (l.empty()) l.push_back(here);
        else {
            if (*(l.end()-1) < here) {
                l.push_back(here);
            } else {
                auto p = lower_bound(l.begin(), l.end(), here);
                *p = here;
            }
        }
    }

    cout << l.size() << endl;
    return 0;
}