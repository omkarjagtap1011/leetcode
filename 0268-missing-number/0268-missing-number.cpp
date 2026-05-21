class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int rangeSum = 0;
        int n = nums.size();

        for(int i=1; i<=n; i++){
            rangeSum+=i;
        }

        int arraySum = 0;
        for(int i=0; i<n; i++){
            arraySum+=nums[i];
        }

        return rangeSum - arraySum;
    }
};