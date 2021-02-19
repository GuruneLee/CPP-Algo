#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10001];

int main() {
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        short tmp;
        scanf("%hd",&tmp);
        arr[tmp] += 1;
    }

    for (int i=1; i<10001; i++) {
        for (int j=0; j<arr[i]; j++) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}