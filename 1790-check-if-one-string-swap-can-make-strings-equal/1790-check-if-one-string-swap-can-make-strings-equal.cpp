class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        string temp1 = s1, temp2 = s2;
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
        
        if(temp1 != temp2)
            return false;
        
        int n = s1.length();
        unordered_set<char> diffChars;
        int diffCount = 0;
        
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                diffCount++;
                diffChars.insert(s1[i]);
                diffChars.insert(s2[i]);
            }
        }
        
        if (diffCount == 0) {
            return true;
        }
        
        if (diffCount == 2 && diffChars.size() == 2) {
            return true;
        }
        
        return false;
    }
};