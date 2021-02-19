#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;
int d[10000][2][2];
int ans = 0;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    d[1][0][0] = 0;
    d[1][0][1] = v[1];
    d[1][1][0] = v[0];
    d[1][1][1] = v[0] + v[1];

    if (n > 1) {
        for (int i = 2; i < n; i++) {
            int a = d[i - 1][0][0];
            int b = d[i - 1][0][1];
            int c = d[i - 1][1][0];
            int D = d[i - 1][1][1];

            d[i][0][0] = a > c ? a : c;
            d[i][0][1] = d[i][0][0] + v[i];
            d[i][1][0] = b > D ? b : D;
            d[i][1][1] = b + v[i];
        }
        int t1 = d[n - 1][0][0] > d[n - 1][0][1] ? d[n - 1][0][0] : d[n - 1][0][1];
        int t2 = d[n - 1][1][0] > d[n - 1][1][1] ? d[n - 1][1][0] : d[n - 1][1][1];
        ans = t1 > t2 ? t1 : t2;
    }
    else if (n==1){
        ans = v[0];
    }
    

    cout << ans << endl;



    return 0;
}