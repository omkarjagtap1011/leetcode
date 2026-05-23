class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        int i;
        bool found = false;
        for(i=1; i<n; i++){
            if(nums[i] < nums[i-1]){
                found = true;
                break;
            }
        }

        if(!found){
            return true;
        }

        int j = (i+1) % n;
        int prev = i;
        while(j!=i){
            if(nums[j]<nums[prev]){
                return false;
            }
            prev = j;
            j = (j+1) % n;
        }
        return true;
    }
};