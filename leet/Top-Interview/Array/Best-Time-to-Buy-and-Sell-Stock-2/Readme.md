# Best Time to Buy and Sell Stock 2
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

## Peak-Valley Theorem
| 증가함수일 때만 더하면 최대 이익이 나옴...
profit  = SUM( Peak[i] + Valley[i] )
        = SUM(Peak[i]) - SUM(Valley[i])
        = SUM(P[i] - P[j], if P[i] > P[j] ) 

## Source Code
### Peak(극대) / Valley(극소) 골라서 다 더하기
~~~
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p = 0;
        if (prices.size() == 1) return 0;
        if (prices.size() == 2) return prices[1] > prices[0] ? prices[1]-prices[0] : 0;
        
        if (prices[0] < prices[1]) //first index valley
            p -= prices[0];
        if (prices[prices.size()-2] < prices[prices.size()-1]) //last index peak
            p += prices[prices.size()-1];
        
        for (int i=1; i<prices.size()-1; i++) {
            if (prices[i-1] < prices[i] && prices[i] >= prices[i+1])
                p += prices[i];
            if (prices[i-1] >= prices[i] && prices[i] < prices[i+1])
                p -= prices[i];
        }
        
        return p;
    }
};
~~~

### 증가함수 일 때만 다 더하기 (not mine)
~~~
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]){
                profit+=prices[i]-prices[i-1];
            }
        }
        
        return profit;
    }
};
~~~
