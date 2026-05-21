class NumArray {
    vector<int> pref;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        pref.resize(nums.size() + 1);

        for(int i=1; i<=n; i++){
            pref[i] = pref[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return pref[right+1] - pref[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);

 // [0, -2, -2, 1, -4, -2, -3]
 */