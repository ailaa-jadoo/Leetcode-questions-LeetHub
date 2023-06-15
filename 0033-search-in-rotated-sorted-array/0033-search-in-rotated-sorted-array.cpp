class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low =0, high = nums.size()-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(nums[mid] == target)
                return mid;
            else if(nums[mid]>=nums[low]){
                if(nums[mid]>=target and target>=nums[low])
                    high=mid-1;
                else
                    low=mid+1;
            }
            else{
                if(nums[mid]<=target and target<=nums[high])
                    low=mid+1;
                else
                    high=mid-1;
            }   
        }
        
        return -1;
    }
};