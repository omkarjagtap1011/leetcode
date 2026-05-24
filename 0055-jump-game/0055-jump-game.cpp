class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[n-1] = true;
        
        for(int i=n-2; i>=0; i--){
            bool flag = false;
            for(int j=1; j<=nums[i]; j++){
                if(i+j < n){
                    bool res = dp[i+j];
                    if(res){
                        dp[i] =  true;
                        flag = true;
                        break;
                    }
                }else break;
            }
            if(!flag){
                dp[i] = false;
            }
        }

        return dp[0];
    }
};