class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(t.size()<s.size())
            return false;
        
        if(s=="")
            return true;
    
        int j=0; //for s;
        
        for(int i=0;i<t.size();i++){ //for t
            if(s[j] == t[i])
                j++;
            
            if(j==s.size())
                return true;
        }
        
        return false;
    }
};