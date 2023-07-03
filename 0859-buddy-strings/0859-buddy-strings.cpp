class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        
        if (s == goal) {
            unordered_set<char> uniqueChars;
            for (char ch : s) {
                if (uniqueChars.count(ch) > 0) {
                    return true;
                }
                uniqueChars.insert(ch);
            }
            return false;
        }
        
        int firstPos = -1, secondPos = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != goal[i]) {
                if (firstPos == -1) {
                    firstPos = i;
                } else if (secondPos == -1) {
                    secondPos = i;
                } else {
                    return false;
                }
            }
        }
        
        return (secondPos != -1 && s[firstPos] == goal[secondPos] && s[secondPos] == goal[firstPos]);
    }
};