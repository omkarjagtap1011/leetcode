class Solution {
    bool whoWins(int n, bool isAliceTurn){
        if(n==1) return !(isAliceTurn);
        for(int i=1; i<n; i++){
            if(n%i == 0){
                return whoWins(n-i, !isAliceTurn);
            }
        }
        return !(isAliceTurn);
    }
public:
    bool divisorGame(int n) {
        return whoWins(n, true);
    }
};