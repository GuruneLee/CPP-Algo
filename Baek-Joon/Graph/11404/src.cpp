#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<vector<int>> graph;

int main() {
    cin >> n >> m;
    graph = vector<vector<int>> (n+1, vector<int>(n+1,987654321));
    for (int i=0; i<m; i++) {
        int a,b,c;
        cin >> a>> b>> c;
        graph[a][b] = min(c, graph[a][b]);
    }

    for (int i=1; i<n+1; i++) {
        graph[i][i] = 0;
    }
    
    for (int i=1; i<n+1; i++) {
        for (int a=1; a<n+1; a++){
        for (int b=1; b<n+1; b++){
            graph[a][b] = min(graph[a][b], graph[a][i] + graph[i][b]);
        }}
    }

    for (int a=1; a<n+1; a++){
        for (int b=1; b<n+1; b++){
            if (graph[a][b] == 987654321) {
                graph[a][b] = 0;
            }
            cout << graph[a][b] << ' ';
        }
        cout << endl;    
    }


    return 0;
}