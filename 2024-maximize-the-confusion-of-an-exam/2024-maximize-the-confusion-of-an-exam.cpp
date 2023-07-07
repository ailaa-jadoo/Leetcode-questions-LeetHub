class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        
        int left =0, cnt=0, res=0;
        
        for(int right=0;right<s.size();right++){
            if(s[right]=='F')
                cnt++;
            
            while(cnt>k){
                if(s[left]=='F')
                    cnt--;
                left++;
            }
            
            res = max(res, right-left+1);
        }
        
        cnt=0, left=0;
        for(int right=0;right<s.size();right++){
            if(s[right]=='T')
                cnt++;
            
            while(cnt>k){
                if(s[left]=='T')
                    cnt--;
                left++;
            }
            
            res = max(res, right-left+1);
        }
        
        return res;
    }
};