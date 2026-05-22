class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        for(int k=0; k<m; k++){
            int i = n-1;
            int j = n-1;

            while(i>=0){
                if(boxGrid[k][i] == '*'){
                    j = i;
                }else if(boxGrid[k][i] == '#'){
                    while(j>i){
                        if(boxGrid[k][j] == '.'){
                            boxGrid[k][j] = '#';
                            boxGrid[k][i] = '.';
                            j--;
                            break;
                        }
                        j--;
                    }
                }

                i--;
            }
        }

        vector<vector<char>> res(n);

        for(int i = 0; i<n; i++){
            for(int j=m-1; j>=0; j--){
                res[i].push_back(boxGrid[j][i]);
            }
        }

        return res;
    }
};