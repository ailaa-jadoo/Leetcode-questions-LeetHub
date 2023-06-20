class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]<=nums[i]){
                operations += (nums[i]-nums[i+1]) + 1;
                nums[i+1] = nums[i]+1;
            }
            else
                continue;
        }
        
        return operations;
    }
};