class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int Rsum = accumulate(begin(nums), end(nums), 0);
        int Lsum=0;
        
        for(int i=0;i<nums.size();i++){
            Rsum -= nums[i];
            
            if(Rsum == Lsum)
                return i;
            
            Lsum += nums[i];
        }
        
        return -1;
    }
};