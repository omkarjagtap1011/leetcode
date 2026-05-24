class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxJ = 0;

        for(int i=0; i<n; i++){
            if(i<=maxJ){
                maxJ = max(maxJ, i+nums[i]);
                maxJ = min(maxJ, n-1);
            }else{
                return false;
            }
        }
        return true;
    }
};