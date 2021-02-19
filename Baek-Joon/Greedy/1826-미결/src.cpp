#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    int d,w;
    priority_queue<pair<int,int>> v; //d, w
    for (int i=0; i<N; i++) {
        cin >> d >> w;
        v.push({-d,w});
    }

    int max_dist, oil;
    int dist = 0;
    cin >> max_dist >> oil;
    priority_queue<pair<int,int>> q; //w,d






    return 0;
}