class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string repeat = word;
        int count = 0;

        while(sequence.contains(repeat)){
            count++;
            repeat += word;
        }
        return count;
    }
};