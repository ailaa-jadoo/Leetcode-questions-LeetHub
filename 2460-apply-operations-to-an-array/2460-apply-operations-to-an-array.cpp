class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        if(n==1 or n==0)
            return nums;
        
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        
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
        
        return nums;
    }
};