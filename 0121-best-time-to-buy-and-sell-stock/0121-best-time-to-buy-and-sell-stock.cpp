class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        int index = 0;

        for(int i=1; i<n; i++){
            int temp = prices[i] - prices[index];
            if(temp>0){
                profit = max(profit, temp);
            }else{
                index = i;
            }
        }
        return profit;
    }
};