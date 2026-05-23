class Solution {
    bool whoWins(int n, bool isAliceTurn, vector<int> dp){
        if(n==1) return !(isAliceTurn);
        if(dp[n] != -1) return dp[n];
        for(int i=1; i<n; i++){
            if(n%i == 0){
                return dp[n] = whoWins(n-i, !isAliceTurn, dp);
            }
        }
        return dp[n] = !(isAliceTurn);
    }
public:
    bool divisorGame(int n) {
        vector<int> dp(n+1, -1);
        return whoWins(n, true, dp);
    }
};