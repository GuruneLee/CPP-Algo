#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> num;
vector<int> op; //0,1,2,3 -> + - x /

int cal() {
    int re = num[0];
    for (int i=1; i<num.size(); i++) {
        if (op[i-1] == 0) {
            re += num[i];
        }
        if (op[i-1] == 1) {
            re -= num[i];
        }
        if (op[i-1] == 2) {
            re *= num[i];
        }
        if (op[i-1] == 3) {
            re /= num[i];
        }
    }
    return re;
}

int r = -987654321;
int l = 987654321;

int main() {
    cin >> N;
    num = vector<int>(N);
    for (int i=0; i<N; i++) {
        cin >> num[i];
    }
    
    for (int i=0; i<4; i++) {
        int tmp;
        cin >> tmp;
        while(tmp--)
            op.push_back(i);
    }

    do {
        int tmp = cal();
        if (tmp > r)  r = tmp;
        if (tmp < l)  l = tmp;
    } while (next_permutation(op.begin(), op.end()));

    cout << r << endl << l ;

    return 0;
}