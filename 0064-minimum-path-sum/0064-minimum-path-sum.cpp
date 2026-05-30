class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0){
                    continue;
                }
                int left = 200000;
                int up = 200000;

                if(j>0) left = grid[i][j-1];
                if(i>0) up = grid[i-1][j];

                grid[i][j] = grid[i][j] + min(left, up);
            }

        }
        return grid[m-1][n-1];
    }
};