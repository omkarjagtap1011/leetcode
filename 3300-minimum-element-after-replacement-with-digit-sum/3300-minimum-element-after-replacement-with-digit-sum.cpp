class Solution {
    int digitsum(int num){
        int sum = 0;
        while(num>0){
            int d = num%10;
            sum+=d;
            num/=10;
        }
        return sum;
    }
public:
    int minElement(vector<int>& nums) {
        int minNum = INT_MAX;
        for(int num: nums){
            minNum = min(minNum, digitsum(num));
        }
        return minNum;
    }
};