class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left =0, res = blocks.size(), cnt=0;
        
        for(int i=0;i<k;i++)
            if(blocks[i]=='W')
                cnt++;
        
        res = cnt;
        
        for(int right = k;right<blocks.size();right++){
            if(blocks[right]=='W')
                cnt++;
            if(blocks[left]=='W')
                cnt--;
            left++;
            
            res = min(res, cnt);
        }
        return res>=0 ? res :0;
    }
};