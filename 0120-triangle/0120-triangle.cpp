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
        dp[0][0] = triangle[0][0];

        for(int row=1; row<m; row++){
            int len = triangle[row].size();
            

            for(int j=0; j<len; j++){
                int mini = INT_MAX;

                if(j<len-1) mini = min(mini, dp[row-1][j]);

                if(j-1>=0) mini = min(mini, dp[row-1][j-1]);

                dp[row][j] = triangle[row][j] + mini;
            }
        }
        return *min_element(dp[m-1].begin(), dp[m-1].end());
    }
};