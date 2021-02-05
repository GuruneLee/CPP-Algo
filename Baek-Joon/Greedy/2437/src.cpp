//저울
//하나의 양팔 저울을 이용한 물건 무게 측정
//무게가 양의 정수인 N개의 저울추
//->측정할 수 없는 양의 정수 무게 중 최솟값 구하기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int tg = 1; //target은 1부터 시작
    for (int i=0; i<n; i++) {
        // tg가 i번째 추보다 작다는 것은 
        // 이전까지 만들었던거에 i번째 추를 더했을 때 빈 곳이 생긴다는 의미
        if (tg < v[i]) {
            break;
        } else {
            //다음 tg를 만들기
            //이놈이 빈곳에 있는놈인지 아닌놈인지 보는거얌
            tg += v[i];
        }
    }
    cout << tg << endl;
    return 0;
}