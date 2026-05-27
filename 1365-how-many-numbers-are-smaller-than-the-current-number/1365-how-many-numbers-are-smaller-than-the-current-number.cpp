class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        map<int, int> freq;

        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }

        int count=0;
        for(auto it: freq){
            freq[it.first] = count;
            count+=it.second;
        }

        for(int i=0; i<n; i++){
            nums[i] = freq[nums[i]];
        }
        
        return nums;
    }
};