//요구르트의 유통기한
//1/15까지임, 모두 먹어야 함
//n개의 요구르트, k개를 먹고싶다(무게가 다 다름)
//불량품은 마시면 안됨
//n개중에 k개를 마실 때 가장 많은 양의 요구르트를 마시면서 불량을 마실 확률이 가장 적은 집합을 받음
//불량을 먹을 확률을 구하세용
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> up(n);

    for (int i=0; i<n; i++) {
        int a,b;
        cin >> a >> b;
        up[i] = {-a,b};
    }
    sort(up.begin(), up.end());

    double p = 1;
    for (int i=0; i<k; i++) {
        p *= 1 - (double)up[i].second / 100;
        p *= 1000;
        p = (int)p;
        p /= 1000;
    }
    p = 1-p;
    
    p *= 1000;
    p = (int)p;
    p /= 1000;
    
    if (p < 0.001) {
        cout << "GG";
    } else {
        printf("%.3lf", p*100);
    }

    return 0;
}