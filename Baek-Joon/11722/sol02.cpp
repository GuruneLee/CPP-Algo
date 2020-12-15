#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> S;

bool comp (int a, int b) {
    return a > b;
}

int main () {
    int n;
    cin >> n;
    
    while(n--) {
        int here;
        scanf("%d", &here);
        if (S.size() == 0) S.push_back(here);
        else {
            if (*(S.end()-1) > here) {
                S.push_back(here);
            } else {
                auto p = lower_bound(S.begin(), S.end(), here, comp);
                *p = here;
            }
        }
    }

    cout << S.size() << endl;
}