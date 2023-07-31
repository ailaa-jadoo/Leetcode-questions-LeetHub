class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int s1_sum=0, s2_sum=0;
        for(char ch:s1)
            s1_sum += ch;
        for(char ch:s2)
            s2_sum += ch;

        vector<vector<int>> t(n+1, vector<int>(m+1, 0));
        
        for(int i=0;i<n+1;i++)
            t[i][0] = 0;
        
        for(int i=1;i<n+1;i++)
            for(int j=1;j<m+1;j++){
                if(s1[i-1] == s2[j-1])
                    t[i][j] = s1[i-1] + t[i-1][j-1];
                else
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        
        return s1_sum+s2_sum-2*t[n][m];
    }
};