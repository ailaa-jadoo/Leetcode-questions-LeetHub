class Solution {
public:
    bool checkString(string s) {
        if(s.size() == 1)
            return true;
        
        string check = s;
        sort(check.begin(), check.end());
                
        return s==check;
    }
};