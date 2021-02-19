#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n,m;
        cin >> n >> m;
        queue<pair<int,int>> q;
        priority_queue<int> imp;
        for (int i=0; i<n; i++) {
            int import;
            cin >> import;
            q.push({import, i});
            imp.push(import);
        }

        int cnt = 0; //인쇄한 문서 수
        while(!q.empty()) {
            int cn = q.front().second; //현재 문서번호
            int ci = q.front().first; //현재 문서 중요도
            q.pop();
            
            int maxi = imp.top(); //현재 최대 문서 중요도
            if (maxi == ci) { //현재 문서 중요도가 최대 중요도 이면
                imp.pop(); //최대 중요도 갱신
                //인쇄하고 m이랑 같은지 확인
                cnt ++;
                if (cn == m) {
                    //같으면 브레이크!
                    break;
                }
            } else { //현재 문서 중요도가 최대가 아니면
                //뒤로 다시 집어넣기
                q.push({ci, cn});
            }
        }
        cout << cnt << endl;
    }
    return 0;
}