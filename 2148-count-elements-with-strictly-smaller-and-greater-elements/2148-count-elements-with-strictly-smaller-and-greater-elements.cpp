class Solution {
public:
    int countElements(vector<int>& nums) {
        
        int count=0;
        
        sort(nums.begin(), nums.end());
        
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]>nums[0] and nums[i]<nums[nums.size()-1])
                count++;
        }
        
        return count;
    }
};