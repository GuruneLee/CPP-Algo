#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> L; //길이가 i인 증가하는 부분수열을 만들 수 있는 마지막 원소 중 가장 작은 값
vector<int> p; //수열의 i번째 원소가 L에 포함될 당시, L내에서 위치하는 인덱스 저장 
vector<int> input;

void display() {
    int i = p.size()-1;
    int l = L.size()-1;
    vector<int> ans;
    while (i > -1) {
        if (p[i] == l) {
           ans.push_back(input[i]);
           l --; 
        }
        i --;
    }

    for (int i=ans.size()-1; i>-1; i--) {
        cout << ans[i] << " ";
    }
}

int main() {
    cin >> n;
    while(n--) {
        int here;
        scanf("%d", &here);
        input.push_back(here);
        int tp = 0;
        if (L.size() == 0) L.push_back(here);
        else {
            if (*(L.end()-1) < here) {
                L.push_back(here);
                tp = L.size()-1;
            } else {
                auto tmp = lower_bound(L.begin(), L.end(), here);
                *tmp = here;
                tp = distance(L.begin(), tmp);
            }
        }
        p.push_back(tp);
    }

    cout << L.size() << endl;

    display();

    return 0;
}