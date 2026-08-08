class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];
        int n = nums.size();

        for(int i=1; i<n; i++){
            currentSum = max(nums[i], nums[i] + currentSum);
            maxSum = max(currentSum, maxSum);
        }

        return maxSum;
    }
};