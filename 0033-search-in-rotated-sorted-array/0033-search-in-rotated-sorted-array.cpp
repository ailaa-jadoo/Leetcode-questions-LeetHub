class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = find(nums.begin(), nums.end(), target);
        if(it == nums.end())
            return -1;
        return distance(nums.begin(), it);
    }
};

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int low =0, high=nums.size();
        
//         while(low<=high){
//             int mid = high - (high-low)/2;
            
//             if(nums[mid] == target)
//                 return mid;
//             else if(nums[mid]){
                
//             }
//         }
//     }
// };