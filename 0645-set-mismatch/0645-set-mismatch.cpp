class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1, 0);

        for(int n: nums){
            freq[n]++;
        }

        int twice;
        int missing;
        for(int i=1; i<=n; i++){
            if(freq[i] == 0){
                missing = i;
            }

            if(freq[i] == 2){
                twice = i;
            }
        }

        return {twice, missing};
    }
};