//보석상자
#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n,m;
    cin >> n >> m;
    vector<long long> v(m);
    long long longest = -1;
    for (long long i=0; i<m; i++) {
        cin >> v[i];
        longest = longest<v[i]?v[i]:longest;
    }
    
    long long result = 987654321;
    long long s = 1, e = longest;
    while (s <= e) {
        long long mid = (s+e)/2;

        //mid개로 몇칸 채울까용?
        long long boxes = 0;
        for (long long i=0; i<m; i++) {
            long long step = v[i]/mid; //v[i]개를 mid개씩 나눠 담았을 때!!
            if (v[i]%mid!=0) {
                step += 1;
            }
            boxes += step;
        }

        if (boxes <= n) {
            result = mid<result?mid:result;
            e = mid-1;
        } else {
            s = mid+1;
        }
    }

    cout << result << endl;
    return 0;
}