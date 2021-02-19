#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n,l,w,h;
    cin >> n >> l >> w >> h;
    double s = 0;
    double e = max({l,w,h});

    //long long  result = 1;
    for (int i=0; i<10000; i++) {
        long double mid = (s+e)/2;
        if (n <= (long long)(l/mid)*(long long)(w/mid)*(long long)(h/mid)) {
            s = mid;
        } else {
            e = mid;
        }
    }

    printf("%.10lf", s);
    return 0;
}