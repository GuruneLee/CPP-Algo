// 알파벳 개수
#include <bits/stdc++.h>
using namespace std;

int freq[100];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin, s); // cin >> s;

    for (char c: s) {
        freq[c - 'a'] += 1;
    }

    for (int i = 'a'; i <= 'z'; i++)
    {
        cout << freq[i-'a'] << ' ';
    }
}