class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1) return {{1}};
        if(numRows==2) return {{1}, {1, 1}};

        vector<vector<int>> res;

        res.push_back({1});
        res.push_back({1, 1});

        for(int i=2; i<numRows; i++){
            vector<int> temp;
            temp.push_back(1);
            vector<int> prev = res[i-1];
            int m = prev.size();

            for(int j=1; j<m; j++){
                temp.push_back(prev[j] + prev[j-1]);
            }

            temp.push_back(1);

            res.push_back(temp);
        }

        return res;
    }
};