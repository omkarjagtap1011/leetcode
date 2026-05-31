class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        long long temp = mass;
        vector<int> count(100001, 0);
        for(int i=0; i<n; i++){
            count[asteroids[i]]++;
        }

        for(int i=1; i<100001; i++){
            if(count[i] != 0){
                if(i>temp) return false;
                temp += (1LL * i * count[i]);
            }
        }
        return true;
    }
};