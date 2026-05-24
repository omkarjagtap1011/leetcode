class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> sym = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        stack<char> stk;
        int n = s.size();
        for(int i=0; i<n; i++){
            char c = s[i];

            switch(c){
                case '(':
                case '{':
                case '[':
                    stk.push(c);
                    break;
                case ')':
                case '}':
                case ']':
                    if(stk.empty()) return false;
                    if(stk.top() == sym[c]){
                        stk.pop();
                    }else return false;
                    break;
                    
            }
        }
        return stk.empty();
    }
};