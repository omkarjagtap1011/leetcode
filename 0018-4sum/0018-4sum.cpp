class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> output;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n-3; i++){
            for(int j = i+1; j<n-2; j++){
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];

                int left = j+1;
                int right = n-1;

                while(left<right){
                    int sum = nums[left] + nums[right];

                    if(sum < newTarget){
                        left++;
                    }else if(sum > newTarget){
                        right--;
                    }else{
                        output.push_back({nums[i], nums[j], nums[left], nums[right]});
                        int tempLeft = left;
                        int tempRight = right;

                        while(left<right && nums[left] == nums[tempLeft]) left++;
                        while(left<right && nums[right] == nums[tempRight]) right--;
                    }
                }
                while(j+1<n && nums[j] == nums[j+1]) j++;
            }
            while(i+1<n && nums[i] == nums[i+1]) i++;
        }
        return output;
    }
};