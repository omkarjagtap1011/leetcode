class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexMap;
        int n = nums.size();

        for(int i=0; i<n; i++){
            int comp = target - nums[i];

            if(indexMap.find(comp) != indexMap.end()){
                return {i, indexMap[comp]};
            }
            indexMap[nums[i]] = i;
        }

        return {0, 0};
    }
};