class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);

        for(int i=0; i<n; i++){
            int smaller = 0;
            for(int j = 0; j<n; j++){
                if(i==j) continue;
                if(nums[j] < nums[i]){
                    smaller++;
                }
            }
            res[i] = smaller;
        }

        return res;
    }
};