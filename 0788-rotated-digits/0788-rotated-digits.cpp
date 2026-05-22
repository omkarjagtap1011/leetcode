class Solution {
public:
    int rotatedDigits(int n) {
        int res = 0;
        unordered_map<int, int> map = 
        {
            {0, 0},
            {1, 1},
            {2, 5},
            {5, 2},
            {6, 9},
            {8, 8},
            {9, 6}
        };
        for(int i=1; i<=n; i++){
            int num = i;
            bool found = true;
            int newNumber = 0;
            int multiplier = 1;

            while(num!=0){
                int d = num%10;
                if(map.find(d) == map.end()){
                    found = false;
                    break;
                }

                newNumber = newNumber + (map[d] * multiplier);
                multiplier *= 10;
                num = num / 10;
            }

            if(found && newNumber != i){
                res++;
            }

        }

        return res;
    }
};