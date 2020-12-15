#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int indp[1001];
int dedp[1001];
int input[1001];

int main () {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        indp[i] = 1;
        dedp[i] = 1;
        scanf("%d", input+i);
        for (int j=0; j<i; j++) {
            if (input[i] > input[j] && indp[i] < indp[j] + 1) {
                indp[i] = indp[j] + 1;
            }
        }
    }
    
    for (int i=n-1; i>-1; i--) {
        for (int j=n-1; j>i; j--) {
            if (input[i] > input[j] && dedp[i] < dedp[j] + 1) {
                dedp[i] = dedp[j] + 1;
            }
        }
    }

    vector<int> ans;
    for (int i=0; i<n; i++) {
        ans.push_back(indp[i] + dedp[i] - 1);
    }

    sort(ans.begin(), ans.end());
    
    cout << *(ans.end()-1) << endl;

    return 0;
}