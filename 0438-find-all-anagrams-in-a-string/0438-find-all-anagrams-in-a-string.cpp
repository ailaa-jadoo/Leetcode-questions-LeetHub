class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> res;
        
        vector<int> shash(26, 0);
        vector<int> phash(26, 0);
        
        int slen = s.size();
        int plen = p.size();
        
        if(plen>slen)
            return res;
        
        int left=0, right=0;
        while(right<plen){
            phash[p[right]-'a']+=1;
            shash[s[right]-'a']+=1;
            right+=1;
        }
        
        right-=1;
        
        while(right<slen){
            if(phash == shash)
                res.push_back(left);
            right+=1;
            if(right!=slen)    
                shash[s[right]-'a']+=1;
            shash[s[left]-'a']-=1;
            left+=1;                
        }
        
        return res;
    }
};
