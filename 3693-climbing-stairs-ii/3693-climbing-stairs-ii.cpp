class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int prev1 = 0;
        int prev2 = 0;
        int prev3 = 0;

        for(int i=1; i<=n; i++){
            int c = costs[i-1];
            int res = prev1 + c + 1;
            if(i>1) res = min(res, prev2 + (costs[i-1] + 4));
            if(i>2) res = min(res, prev3 + (costs[i-1] + 9));

            prev3 = prev2;
            prev2 = prev1;
            prev1 = res;
        }
        return prev1;
    }
};