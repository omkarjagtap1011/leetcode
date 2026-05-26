class Solution {
    bool isLower(char c){
        return (c>=97 && c<=122);
    }

    bool isUpper(char c){
        return (c>=65 && c<=90);
    }

    int getIndex(char c){
        if(isLower(c)) return c-97;
        else return c-65;
    }
public:
    int numberOfSpecialChars(string word) {
        vector<int> freq(26, -1);
        int count = 0;

        for(char c: word){
            int idx = getIndex(c);
            if(freq[idx] == -1){
                if(isLower(c)) freq[idx] = 1;
                else freq[idx] = 2;
            }else if(freq[idx] == 0){
                continue;
            }else{
                if((isLower(c) && freq[idx]==2) || (isUpper(c) && freq[idx] == 1)){
                    freq[idx] = 0;
                    count++;
                }
            }
        }

        return count;

    }
};