class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 200000);
        
        for(int i=0; i<m; i++){
            vector<int> curr(n, 0);
            for(int j=0; j<n; j++){
                if(i==0 && j==0){
                    curr[0] = grid[0][0];
                    continue;
                }
                int left = 200000;
                int up = 200000;

                if(j>0) left = curr[j-1];
                up = prev[j];

                curr[j] = grid[i][j] + min(left, up);
            }
            prev = curr;
        }
        return prev[n-1];
    }
};