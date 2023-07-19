class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), count=0;
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                string subs = s.substr(i, j-i+1);
                string temp = subs;
                reverse(temp.begin(), temp.end());
                if(temp == subs)
                    count++;
            }
        }
        
        return count;
    }
};