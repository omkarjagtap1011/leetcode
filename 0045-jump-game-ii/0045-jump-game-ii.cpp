class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[n-1] = 0;
        for(int idx = n-2; idx>=0; idx--){
            int res = INT_MAX;
            for(int j=1; j<=nums[idx]; j++){
                if(idx+j < n){
                    int temp = dp[idx+j];
                    if(temp != INT_MAX)
                        res = min(res, 1 + temp);
                }else{
                    break;
                }
            }
            dp[idx] = res;
        }
        return dp[0];
    }
};