class Solution {
    bool good(int num){
        int diff = 0;
        while(num!=0){
            int d = num%10;
            
            if(d == 3 || d == 7 || d == 4){
                return false;
            }

            if(d == 2 || d == 5 || d == 6 || d == 9){
                diff++;
            }  
            num = num / 10;
        }
        if(diff>0) return true;
        return false;
}
public:
    int rotatedDigits(int n) {
        int res = 0;
        for(int i=1; i<=n; i++){
            if(good(i)){
                res++;
            }
        }

        return res;
    }
};