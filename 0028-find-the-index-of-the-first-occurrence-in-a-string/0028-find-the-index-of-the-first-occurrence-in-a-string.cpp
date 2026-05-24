class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        if(n>m) return -1;

        int j=0;
        int i=0;
        while(i<m){
            if(needle[j] == haystack[i]){
                j++;
            }else{
                i = i-j;
                j=0;
            }

            if(j==n){
                return i-n+1;
            }

            i++;
        }
        return -1;
    }
};