class Solution {
public:
    int maxVowels(string s, int k) {
        int left =0, res = s.size(), cnt=0;
        
        for(int i=0;i<k;i++)
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u')
                cnt++;
        
        res = cnt;
        
        for(int right = k;right<s.size();right++){
            if(s[right]=='a' or s[right]=='e' or s[right]=='i' or s[right]=='o' or s[right]=='u')
                cnt++;
            if(s[left]=='a' or s[left]=='e' or s[left]=='i' or s[left]=='o' or s[left]=='u')
                cnt--;
            left++;
            
            res = max(res, cnt);
        }
        return res>=0 ? res :0;
    }
};