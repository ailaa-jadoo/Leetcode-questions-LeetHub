// ref https://leetcode.com/problems/shortest-common-supersequence/discuss/1931964/AdityaVermaSir-DP-solution-or-TopDown
// adity verma dp playlist


class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int n = a.size();
        int m = b.size();
        
        vector<vector<int>> t(n+1, vector<int>(m+1, 0));
        
        for(int i=0;i<n+1;i++)
            t[i][0] = 0;
        
        for(int i=1;i<n+1;i++)
            for(int j=1;j<m+1;j++){
                if(a[i-1] == b[j-1])
                    t[i][j] = 1+t[i-1][j-1];
                else
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        
        int LCS = t[n][m];
        cout<<LCS<<endl;
        
        string res = "";
        int i = n, j = m;
        while(i>0 and j>0){
            if(a[i-1] == b[j-1]){
                res.push_back(a[i-1]);
                i--;
                j--;
            }
            else{
                if(t[i-1][j]>t[i][j-1]){
                    res.push_back(a[i-1]);
                    i--;
                }else{
                    res.push_back(b[j-1]);
                    j--;
                }
            }
        }
        
        while(i>0){
            res.push_back(a[i-1]);
            i--;
        }
        while(j>0){
            res.push_back(b[j-1]);
            j--;
        }
        
        reverse(res.begin(), res.end());
        return res;            
    }
};