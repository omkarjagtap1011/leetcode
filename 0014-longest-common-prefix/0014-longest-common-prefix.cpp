class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size();
        
        int minlen = 201;
        string minword = "";

        for(int i=0; i<n; i++){
            if(strs[i].size() < minlen){
                minlen = strs[i].size();
                minword = strs[i];
            }
        }

        for(int i=0; i<minlen; i++){
            char letter = minword[i];
            for(int j=0; j<n; j++){
                if(letter != strs[j][i]){
                    return ans;
                }
            }
            ans+=letter;
        }

        return ans;
        
    }
};