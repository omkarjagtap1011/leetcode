class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        if(n==1) return nums;

        vector<int> res;

        for(int i=0; i<n; i++){
            res.push_back(nums[i]);
            res.push_back(nums[n+i]);
        }

        return res;
    }
};