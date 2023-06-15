class Solution {
public:
    bool isFascinating(int n) {
        string bum = to_string(n)+to_string(2*n)+to_string(3*n);
        
        vector<int> hash(10,0);
        
        for(auto b : bum){
            hash[b-'0']++;
        }
        
        if(hash[0]!=0)
            return false;
        
        for(int i=1;i<hash.size();i++)
            if(hash[i]==0 or hash[i]>1)
                return false;
        
        return true;
    }
};