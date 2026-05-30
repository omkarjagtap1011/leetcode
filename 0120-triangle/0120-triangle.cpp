class Solution {
    int recur(int row, int last, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(row==0){
            return triangle[0][0];
        }
        if(dp[row][last] != -1){
            return dp[row][last];
        }
        int mini = INT_MAX;
        int len = triangle[row].size();
        
        if(last<len){
            mini = min(mini, triangle[row][last] + recur(row-1, last, triangle, dp));
        }

        if(last-1 >=0){
            mini = min(mini, triangle[row][last-1] + recur(row-1, last-1, triangle, dp));
        }

        return dp[row][last] = mini;
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            mini = min(mini, recur(m-1, i, triangle, dp));
        }
        return mini;
    }
};