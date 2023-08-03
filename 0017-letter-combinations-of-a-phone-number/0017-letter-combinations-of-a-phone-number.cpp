class Solution {
public:
    vector<string> KEYS = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    
    void func(string temp, string digits, int idx, vector<string>& res){
        if(idx>=digits.size())
            res.push_back(temp);
        else{
            string letters = KEYS[digits[idx] - '0'];
            for(char letter: letters)
                func(temp+letter, digits, idx+1, res);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        
        if(digits.empty())
            return res;
        
        func("", digits, 0, res);
        return res;
    }
};