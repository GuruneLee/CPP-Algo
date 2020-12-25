#include <iostream>


using namespace std;

int lcm(int A, int B) {
    int gcd=1;
    int C = A>B?A:B;
    for (int mod=1; mod<C; mod++) {
        if (A%mod==0 && B%mod==0) {
            A = A/mod;
            B = B/mod;
            gcd *= mod;
        }
    }
    return gcd*A*B;
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        int M,N;
        int x,y;
        cin >> M >> N >> x >> y;
        
        int cnt = -1;
        int LCM = lcm(M,N);
        for (int h=0; h<LCM/M; h++) {
            int tmp = (M*h+x)%N;
            //cout << tmp << endl;
            if (tmp == 0) {
                tmp = N;
            }
            if (y == tmp) {
                cnt = M*h+x; 
                break;
            }
        }

        cout << cnt << endl;

    }
    return 0;
}