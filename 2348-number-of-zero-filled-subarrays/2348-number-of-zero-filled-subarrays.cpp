class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long total=0;
        int i=0;
        while(i<nums.size()){
            long long count=0;
            while(i<nums.size() and nums[i]==0){
                count+=1;
                total+=count;
                i++;
            }
            i++;
        }
        
        return total;
    }
};