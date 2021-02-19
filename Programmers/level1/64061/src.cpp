#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> basket;

//[1,5,3,5,1,2,1,4]

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    for (auto m : moves) {
        int where = m-1;
        for (int i=0; i<board.size(); i++) {
            if (board[i][where] != 0) {
                basket.push_back(board[i][where]);
                board[i][where] = 0;
                break;
            }
        }
    }
    
    bool keepGoing = true;
    while (basket.size() > 1 && keepGoing){
        keepGoing = false;
        for (int i=1; i<basket.size(); i++) {
            if (basket[i-1] == basket[i]) {
                keepGoing = true;
                answer += 2;
                basket.erase(basket.begin()+i-1);
                basket.erase(basket.begin()+i-1);
            }
        }
    }
    
    return answer;
}

int main() {
    vector<vector<int>> board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> moves = {1,5,3,5,1,2,1,4};
    cout << solution(board, moves) << endl;
    return 0;
}