#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    priority_queue<pair<int,int>> pq;

    long long sum = 0; //k가 sum이상이면, k시간이 가기전에 다 먹을 것이므로 답은 -1이됨
    for (int i=0; i<food_times.size(); i++) {
        sum += food_times[i];
        pq.push({-food_times[i], i+1});
    }

    if (sum <= k) {
        return -1;
    }

    int pt = 0;
    int num_of_food = food_times.size();
    while (true) {
        int ct = -pq.top().first;

        long long time_to_eat = (long long)(ct-pt)*(long long)num_of_food; //걸리는 시간 = 모든 음식을 가장 적게 남은 음식만큼 먹을 때 걸리는 시간 -> 현재 고려할 음식은 항상 1번 음식으로 고정임 ㅇㅇ
        pt = ct; //이전 음식시간에 저장하기

        if (time_to_eat > k) { //남은 k시간보다 먹는 시간이 더 걸리거나 같으면, 남은 것들 중 답이 있다는 거임
            //남은 거 꺼내서 index별로 나열하기
            vector<int> leave_food;
            while (!pq.empty()) {
                leave_food.push_back(pq.top().second);
                pq.pop();
            }
            //k초에 num_of_food만큼 몇 번 먹고, 몇 개 더 먹을 수 있을까
            k = k%(long long)num_of_food; //만큼 더 먹을 수 있음

            sort(leave_food.begin(), leave_food.end(), less<>());
            answer = leave_food[k];

            break;
        }

        pq.pop();
        //k에서 먹는 시간만큼 제하기
        num_of_food --; //음식하나 처리!
        k -= time_to_eat;
    }
    return answer;
}

int main() {
    vector<int> ft =  { 3,1,2};
    long long k = 5;

    cout << solution(ft, k) << endl;
    
    return 0;
}