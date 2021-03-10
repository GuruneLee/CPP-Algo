#include <iostream>
#include <vector>

using namespace std;

int n,m;
int h;
vector<int> dd;

bool isOK(int l) {
    long long sum = 0;
    for (auto d : dd) {
        if (d > l) { //떡이 더 길면 잘라서
            sum += (long long)(d - l);
        }
    }
    
    return sum >= (long long)m;
}

int main() {
    cin >> n >> m;
    dd = vector<int> (n, 0); //떡 리스트
    int max_len = -1; //떡 최대 길이
    for (int i=0; i<n; i++) {
        cin >> dd[i];
        max_len = max_len<dd[i]?dd[i]:max_len;
    }

    int s = 0;
    int e = max_len;
    while (s<=e) {
        int mid = (s+e)/2;
        if (isOK(mid)) { //m이상을 가져갈 수 있으면
            h = mid; //m을 일단 답으로 하고, 한 번 더 돌려봐
            s = mid+1; 
        } else {
            e = mid-1; //아니면, e를 m-1로 줄이자
        }
    }

    cout << h ;

    return 0;
}