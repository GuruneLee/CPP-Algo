#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

char ue[10];
//int digit[10] = {0,1,2,3,4,5,6,7,8,9};
int sel1[10] = {0,0,0,0,0,0,0,0,0,0};
int sel2[10] = {0,0,0,0,0,0,0,0,0,0};

int max = 0;
int min = 987654321;

bool check(vector<int>& d, int K) {
    for (int i=0; i<K; i++) {
        if (ue[i] == '<' && d[i] > d[i+1]) {
            return false;
        }
        if (ue[i] == '>' && d[i] < d[i+1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int K;
    cin >> K;
    for (int i=0; i<K; i++) {
        cin >> ue[i];
    }
    bool isExit = false;

    vector<int> max;
    vector<int> min;
    for (int i=9; i>=9-K; i--) {
        max.push_back(i);
    }
    for (int i=0; i<=K; i++) {
        min.push_back(i);
    }

    do {
        if (check(max, K)) {
            for (auto e : max) {
                cout << e;
            }
            cout << endl;
            break;
        } 
    } while(prev_permutation(max.begin(), max.end()));

    do {
        if (check(min, K)) {
            for (auto e : min) {
                cout << e;
            }
            cout << endl;
            break;
        } 
    } while(next_permutation(min.begin(), min.end()));

    return 0;
}