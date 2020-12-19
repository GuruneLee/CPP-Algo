#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> L; //길이가 i인 증가하는 부분수열을 만들 수 있는 마지막 원소 중 가장 작은 값
int main() {
    cin >> n;
    while(n--) {
        int here;
        scanf("%d", &here);
        if (L.size() == 0) L.push_back(here);
        else {
            if (*(L.end()-1) < here) {
                L.push_back(here);
            } else {
                auto tmp = lower_bound(L.begin(), L.end(), here);
                *tmp = here;
            }
        }
    }

    cout << L.size() << endl;

    return 0;
}