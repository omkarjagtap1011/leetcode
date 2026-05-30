class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                int leftdown = 100000;
                int rightdown = 100000;

                if(j-1>=0)
                    leftdown = matrix[i][j] + matrix[i+1][j-1];

                int down = matrix[i][j] + matrix[i+1][j];

                if(j+1<n)
                    rightdown = matrix[i][j] + matrix[i+1][j+1];

                matrix[i][j] = min({leftdown, down, rightdown});
            }
        }

        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};