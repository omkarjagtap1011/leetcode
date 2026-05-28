class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp(n, 0);
        for(int i=0; i<n; i++){
            dp[i] = matrix[0][i];
        }

        for(int row=1; row<n; row++){
            vector<int> temp(n, INT_MAX);
            for(int curcol=0; curcol<n; curcol++){
                for(int prevcol=0; prevcol<n; prevcol++){
                    if(abs(prevcol-curcol) <= 1){
                        int score = matrix[row][curcol] + dp[prevcol];
                        temp[curcol] = min(temp[curcol], score);
                    }
                }
            }
            dp = temp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};