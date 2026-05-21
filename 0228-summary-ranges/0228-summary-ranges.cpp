class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        long long n=nums.size();

        if(n==0) return {};

        vector<string> res;

        long long rangeStart = nums[0];
        long long expected = 1LL * nums[0] + 1;

        for(long long i=1; i<n; i++){
            if(nums[i] == expected){
                expected++;
            }else{
                if((expected - rangeStart) == 1){
                    res.push_back(to_string(rangeStart) + "");
                }else{
                    res.push_back(to_string(rangeStart) + "->" + to_string(nums[i-1]));
                }

                rangeStart = nums[i];
                expected = 1LL * nums[i] + 1;
            }
        }

        if((expected - rangeStart) == 1){
            res.push_back(to_string(rangeStart) + "");
        }else{
            res.push_back(to_string(rangeStart) + "->" + to_string(nums[n-1]));
        }

        return res;
    }
};