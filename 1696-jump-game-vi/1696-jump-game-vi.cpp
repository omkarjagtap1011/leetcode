class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        deque<int> dq;
        dp[0] = nums[0];
        dq.push_back(0);
        
        for(int idx=1; idx<n; idx++){
            while(!dq.empty() && dq.front() < idx-k){
                dq.pop_front();
            }

            dp[idx] = nums[idx] + dp[dq.front()];

            while(!dq.empty() && dp[dq.back()] <= dp[idx]){
                dq.pop_back();
            }

            dq.push_back(idx);
        }

        return dp[n-1];
    }
};