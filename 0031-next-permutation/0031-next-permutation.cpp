class Solution {
    void swapArr(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void reverseArr(vector<int>& nums, int i, int j){
        while(i<j){
            swapArr(nums, i, j);
            i++;
            j--;
        }
    }                                             
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return;
        if(n==2){
            swapArr(nums, 0, 1);
            return;
        }

        int index1=-1;
        int index2=-1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                index1 = i;
                break;
            }
        }

        if(index1==-1){
            reverseArr(nums, 0, n-1);
            return;
        }

        for(int i=n-1; i>=0; i--){
            if(nums[i] > nums[index1]){
                index2 = i;
                break;
            }
        }

        swapArr(nums, index1, index2);
        reverseArr(nums, index1+1, n-1);
    }
};