class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> charmapS;
        unordered_map<char, int> charmapT;
        int n = s.size();

        for(int i=0; i<n; i++){
            if(charmapS.find(s[i]) == charmapS.end()){
                charmapS[s[i]] = i;
            }

            if(charmapT.find(t[i]) == charmapT.end()){
                charmapT[t[i]] = i;
            }

            if(charmapS[s[i]] != charmapT[t[i]]){
                return false;
            }
        }

        return true;
    }
};