class Solution {
    int getNextNumber(int n){
        int res = 0;
        while(n>0){
            int d = n%10;
            res += (d * d);
            n = n/10;
        }
        return res;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> visit;

        while(visit.find(n) == visit.end()){
            visit.insert(n);
            n = getNextNumber(n);
            if(n==1) return true;
        }

        return false;
    }
};