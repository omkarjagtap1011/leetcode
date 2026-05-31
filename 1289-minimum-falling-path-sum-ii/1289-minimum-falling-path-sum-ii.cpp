class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=n-2; i>=0; i--){
            int min1 = INT_MAX;
            int min2 = INT_MAX;
            int minCol = -1;
            for(int j=0; j<n; j++){
                if(matrix[i+1][j] < min1){
                    min2 = min1;
                    min1 = matrix[i+1][j];
                    minCol = j;
                }else if(matrix[i+1][j] < min2){
                    min2 = matrix[i+1][j];
                }
            }

            for(int j=0; j<n; j++){
                matrix[i][j] += (j==minCol?min2:min1);
            }
        }

        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};