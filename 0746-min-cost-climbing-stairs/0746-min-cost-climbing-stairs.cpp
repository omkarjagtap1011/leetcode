class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int n = cost.size();
        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i=2; i<n; i++){
            int fs = cost[i] + prev1;
            int ss = INT_MAX;
            if(i>1)
                ss = cost[i] + prev2;

            int curr = min(fs, ss);

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};