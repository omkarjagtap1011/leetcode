class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;

        long long temp = x;
        long long rev = 0;
        while(x>0){
            int d = x % 10;
            rev = (1LL * rev*10) + d;
            x = x / 10;
        }
        return (temp == rev);
    }
};