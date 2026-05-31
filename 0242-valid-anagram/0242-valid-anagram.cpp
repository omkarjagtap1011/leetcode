class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> charmap;

        for(char c: s){
            charmap[c]++;
        }

        for(char c: t){
            if(!charmap[c]) return false;
            else charmap[c]--;
        }

        return true;
    }
};