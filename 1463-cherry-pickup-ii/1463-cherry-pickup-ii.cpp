class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int dj1 = 0; dj1<n; dj1++){
            for(int dj2 = 0; dj2<n; dj2++){
                if(dj1 == dj2) dp[dj1][dj2] = grid[m-1][dj2];
                else dp[dj1][dj2] = grid[m-1][dj1] + grid[m-1][dj2];
            }
        }

        for(int i=m-2; i>=0; i--){
            vector<vector<int>> temp(n, vector<int>(n, 0));
            for(int j1 = 0; j1<n; j1++){
                for(int j2 = 0; j2<n; j2++){
                    int maxi = -1e8;

                    for(int dj1 = -1; dj1<2; dj1++){
                        for(int dj2 = -1; dj2<2; dj2++){
                            int newj1 = j1+dj1;
                            int newj2 = j2+dj2;
                            if(newj1>=0 && newj1<n && newj2>=0 && newj2<n) maxi = max(maxi, dp[newj1][newj2]);
                        }
                    }

                    if(j1==j2) temp[j1][j2] = grid[i][j1] + maxi;
                    else temp[j1][j2] = grid[i][j1] + grid[i][j2] + maxi;
                }
            }
            dp = temp;
        }

        return dp[0][n-1];
    }
};