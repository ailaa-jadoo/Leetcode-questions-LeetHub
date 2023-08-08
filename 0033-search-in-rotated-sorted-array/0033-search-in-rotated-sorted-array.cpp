// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         auto it = find(nums.begin(), nums.end(), target);
//         if(it == nums.end())
//             return -1;
//         return distance(nums.begin(), it);
//     }
// };

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low =0, high=nums.size()-1;
        
        while(low<=high){
            int mid = high - (high-low)/2;
            
            if(nums[mid] == target)
                return mid;
            else if(nums[low]<=nums[mid]){ //left sorted
                if(nums[low]<=target and nums[mid]>=target)
                    high = mid-1;
                else
                    low = mid+1;
            }else{ //right sorted
                if(nums[high]>=target and nums[mid]<=target)
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        
        return -1;
    }
};