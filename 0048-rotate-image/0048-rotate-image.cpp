class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();

        for(int i=0; i<m; i++){
            int left = 0;
            int right = m-1;

            while(left<right){
                int temp = matrix[i][left];
                matrix[i][left] = matrix[i][right];
                matrix[i][right] = temp;

                left++;
                right--;
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<m-i; j++){
                int k = m - j - 1;
                int l = m - i - 1;

                int temp = matrix[i][j];
                matrix[i][j] = matrix[k][l];
                matrix[k][l] = temp;

            }
        }
    }
};