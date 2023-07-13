class Solution {
public:   
    int LCS(string &s1, string &s2, int n, int m, vector<vector<int>>& t){ 
        if(n == 0 || m == 0) 
            return 0;
        
        if(t[n][m] != -1) 
            return t[n][m];
        
        if(s1[n-1] == s2[m-1])
            return t[n][m] = 1 + LCS( s1, s2, n-1, m-1, t);
        else
            return t[n][m] = max(LCS( s1, s2, n, m-1, t), LCS( s1, s2, n-1, m, t));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size() , m = text2.size();
        vector<vector<int>> t(n+1, vector<int>(m+1, -1));
        return LCS(text1, text2, n, m, t);
    }
};