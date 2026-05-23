class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slen = s.size();
        int tlen = t.size();
        
        if(slen==0) return true;
        if(slen>tlen) return false;

        int j=0;

        for(int i=0; i<tlen; i++){
            if(j==slen) return true;

            if(s[j] == t[i]){
                j++;
            }
        }

        return j==slen;
    }
};