class Solution {
public:
    
    int maxLen(string s, int k, char ch){
        int left =0, cnt=0, res=0;
        for(int right=0;right<s.size();right++){
            if(s[right]==ch)
                cnt++;
            
            while(cnt>k){
                if(s[left]==ch)
                    cnt--;
                left++;
            }
            
            res = max(res, right-left+1);
        }
        return res;
    }
    
    int maxConsecutiveAnswers(string s, int k) {      
        return max(maxLen(s,k,'T'), maxLen(s,k,'F'));
    }
};