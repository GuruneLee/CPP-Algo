#include <bits/stdc++.h>
using namespace std;

int func2(int arr[], int N){
    int narr[101];
    fill(narr, narr + 101, 0);

    for (int i = 0; i < N; i++) {
        if (narr[arr[100-i]] > 0) {
            return 1;
        }
        narr[arr[i]]++;
    }

    return 0;
}

int main() {
    int arr[] = {1, 52, 48};
    cout << func2(arr, 3);
}