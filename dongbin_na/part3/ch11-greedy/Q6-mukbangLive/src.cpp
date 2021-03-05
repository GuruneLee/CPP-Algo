#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    
    long long c_time = 0;
    int c_food = 0;
    int toEat = 0;
    while (true) {
        c_food %= food_times.size();

        if (c_food == 0)    
            toEat ++;

        if (food_times[c_food] >= toEat) {
            if (c_time == k) { //k초일때의 c_food가 답!
                answer = c_food+1;
                break;    
            }
            c_time ++; //다 먹은건 그냥 지나가기
        }
        
        c_food ++;
    }


    return answer;
}

int main() {
    vector<int> ft = {3,1,2};
    long long k = 5;

    cout << solution(ft, k) << endl;
    
    return 0;
}