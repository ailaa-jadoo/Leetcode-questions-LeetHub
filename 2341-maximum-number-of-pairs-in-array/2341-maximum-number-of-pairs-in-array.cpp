class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> hash(101, 0);
        
        for(int num:nums)
            hash[num]++;
        
        int leftOvers=0, pairs=0;
        
        for(int x:hash){
            pairs+= x/2;
            leftOvers+= x%2;
        }        
        return {pairs, leftOvers};
    }
};