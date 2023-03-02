class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> hash(501, 0);
        for(int num:nums)
            hash[num]++;
        
        for(int x:hash)
            if(x%2!=0)
                return false;
        
        return true;
    }
};