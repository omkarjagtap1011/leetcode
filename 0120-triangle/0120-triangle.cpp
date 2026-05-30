class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int> dp(m);
        for(int i=0; i<m; i++){
            dp[i] = triangle[m-1][i];
        }

        for(int i=m-2; i>=0; i--){
            int n = triangle[i].size();
            vector<int> temp(n, 0);
            for(int j=0; j<n; j++){
                int down = triangle[i][j] + dp[j];
                int diag = triangle[i][j] + dp[j+1];
                temp[j] = min(down, diag);
            }
            dp = temp;
        }
        return dp[0];
    }
};