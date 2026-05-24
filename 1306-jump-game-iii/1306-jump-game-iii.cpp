class Solution {
    bool f(int idx, vector<int>& arr, int n, vector<bool>& visited, vector<int>& dp){
        if(arr[idx] == 0) return true;
        if(visited[idx]) return false;
        if(dp[idx] !=- 1) return dp[idx];
        visited[idx] = true;

        bool fs = false;
        bool ss = false;
        if(idx + arr[idx] <n){
            fs = f(idx+arr[idx], arr, n, visited, dp);
        }

        if(idx-arr[idx] >= 0){
            ss = f(idx - arr[idx], arr, n, visited, dp);
        }

        visited[idx] = false;
        return dp[idx] = (fs || ss);
    }    
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        vector<int> dp(n, -1);
        return f(start, arr, n, visited, dp);
    }
};