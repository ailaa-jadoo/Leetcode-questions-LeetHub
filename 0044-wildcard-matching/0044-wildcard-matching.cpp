class Solution {
public:
    
    bool isAllStars(string s, int i){
        for (int j = 1; j <= i; j++) 
            if (s[j - 1] != '*')
                return false;
        
          return true;
    }
    
    bool isMatch(string s2, string s1) {
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<bool>> t(n+1, vector<bool>(m+1, false));
        
        t[0][0] = true;
        
        for(int j=1;j<m+1;j++)
            t[0][j] = false;
        
        for(int i=1;i<n+1;i++)
            t[i][0] = isAllStars(s1, i);
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1] or s1[i-1]=='?')
                    t[i][j] = t[i-1][j-1];
                else{
                    if(s1[i-1]=='*')
                        t[i][j] = t[i-1][j] or t[i][j-1];
                    else
                        t[i][j] = false;
                }
            }
        }
        
        
        return t[n][m];
    }
};