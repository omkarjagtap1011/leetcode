class Solution {
    void reverseArr(vector<int>& nums, int i, int j){
        while(i<j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;

            i++;
            j--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverseArr(nums, n-k, n-1);
        reverseArr(nums, 0, n-k-1);
        reverseArr(nums, 0, n-1);
    }
};