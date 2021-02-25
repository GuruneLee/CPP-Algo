#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (auto cmd : commands) {
        int i = cmd[0]-1;
        int j = cmd[1]-1;
        int k = cmd[2]-1;

        vector<int> v(array.begin()+i, array.begin()+j+1);
        sort(v.begin(), v.end());
        int tmp = v[k];
        answer.push_back(tmp);
    }
    return answer;
}

int main() {
    vector<int> arr = {1,5,2,6,3,7,4};
    vector<vector<int>> cmd = {{2,5,3},{4,4,1},{1,7,3}};
    auto tmp = solution(arr, cmd);
    return 0;
}