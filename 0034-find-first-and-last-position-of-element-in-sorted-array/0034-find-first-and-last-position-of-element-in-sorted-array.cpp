class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res = {-1, -1};
        for(int i=0; i<n; i++){
            if(nums[i] == target){
                res[0] = i;
                while(i<n-1 && nums[i] == nums[i+1]){
                    i++;
                }
                res[1] = i;
                return res;
            }
        }
        return res;
    }
};