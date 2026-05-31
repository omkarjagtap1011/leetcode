class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                int mini = INT_MAX;
                for(int prev=0; prev<n; prev++){
                    if(prev!=j){
                        mini = min(mini, matrix[i+1][prev]);
                    }
                }
                matrix[i][j] += mini;
            }
        }

        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};