# include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        double x1, y1, r1;
        double x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2 ;
        double d = sqrt(pow((x1-x2),2) + pow((y1-y2),2));
   // cout << d << endl;
   // cout << r1 << " " << r2 << endl;
        if (d == 0) {
            if (r1==r2)
                cout << -1 <<endl;
            else
                cout << 0 << endl;
        } else if (d < abs(r1-r2) || d > r1+r2) {
            cout<< 0 <<endl;
        } else if (abs(r1-r2) == d || r1+r2 == d) {
            cout<< 1 <<endl;
        } else if (abs(r1-r2) < d && d < r1+r2) {
            cout << 2 << endl;
        }

    }



    return 0;
}
