class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // auto last = unique(nums.begin(), nums.end());
        // return last-nums.begin();
        
        int i=0;
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]!=nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        
        return i+1;
    }
};