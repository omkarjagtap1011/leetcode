class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        for(int i=m-2; i>=0; i--){
            for(int j=0; j<=i; j++){
                int down = triangle[i+1][j];
                int diag = triangle[i+1][j+1];
                triangle[i][j] += min(down, diag);
            }
        }
        return triangle[0][0];
    }
};