#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> ans;

void display() {
    for (auto a : ans) {
        cout << a << " ";
    }
    cout << "\n";
}

void go (int curV, int curP) { //현재 값, 현재 몇번째인지
    //back-tracking


    //종료조건
    if (curP == M) { //출력 크기 초과
        return;
    }
    for (int i=0; i<curP; i++) {
        if (ans[i] == curV) { //저장되어있던 값이 cur과 같으면 수열 x
            return;
        }
    }

    if (ans.size() == M) {
        display(); //답 출력
        return;
    }

    for (int i=1; i<=N; i++) {
        ans.push_back(i); //배열에 값 저장
        go(i, curP+1);
        ans.pop_back();
    }
}

int main() {
    cin >> N >> M;

    int r=0;
    for (int i=1; i<=N; i++) {
        ans.push_back(i); //배열에 값 저장
        go(i,0);
        ans.pop_back();
    }

    return 0;
}