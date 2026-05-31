class Solution {
    int recur(int row, int col1, int col2, vector<vector<int>>& grid, int m, int n, vector<vector<vector<int>>>& dp){
        if(col1<0 || col1>=n || col2<0 || col2>=n) return -1e8;

        if(row==m-1){
            if(col1==col2) return grid[row][col1];
            else return grid[row][col1] +  grid[row][col2];
        }

        if(dp[row][col1][col2] != -1) return dp[row][col1][col2];

        int maxi = -1e8;
        for(int dj1 = -1; dj1<2; dj1++){
            for(int dj2 = -1; dj2<2; dj2++){
                maxi = max(maxi, recur(row+1, col1+dj1, col2+dj2, grid, m, n, dp));
            }
        }

        if(col1==col2) return dp[row][col1][col2] = grid[row][col1] + maxi;
        else return dp[row][col1][col2] = grid[row][col1] + grid[row][col2] + maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return recur(0, 0, n-1, grid, m, n, dp);
    }
};