class Solution {
public:
    int maxLen(string s, int k, char ch){
        int left =0, cnt=0, res=0;
        
        for(int right = 0;right<s.size();right++){
            if(s[right] != ch)
                cnt++;
            while(cnt>k){
                if(s[left]!=ch)
                    cnt--;
                left++;
            }
            
            res = max(res, right-left+1);
        }
        
        return res;
    }
    
    int characterReplacement(string s, int k) {
        int res = 0;
        vector<int> count(27,0);
        for(int i=0;i<s.size();i++)
            count[s[i]-'A']++;
                  
        for(char ch = 'A'; ch<='Z';ch++)
            if(count[ch-'A']!=0)
                res = max(res, maxLen(s,k,ch));
        
        return res;
    }
};