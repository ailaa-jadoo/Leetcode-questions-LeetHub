class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n==1 or n==0)
            return;
        
        int left=0, right=0;
        while(right<n){
            if(nums[right]==0)
                ++right;
            else{
                swap(nums[left], nums[right]);
                left++;
                right++;
            }
        }
    }
};