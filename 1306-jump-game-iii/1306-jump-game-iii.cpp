class Solution {
    bool f(int idx, vector<int>& arr, int n, vector<bool>& visited){
        if(arr[idx] == 0) return true;
        if(visited[idx]) return false;

        visited[idx] = true;

        bool fs = false;
        bool ss = false;
        if(idx + arr[idx] <n){
            fs = f(idx+arr[idx], arr, n, visited);
        }

        if(idx-arr[idx] >= 0){
            ss = f(idx - arr[idx], arr, n, visited);
        }

        visited[idx] = false;
        return (fs || ss);
    }    
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        return f(start, arr, n, visited);
    }
};