// O(N) Kadane

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN;
        int sum = 0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            res = max(res, sum);
            if(sum<0)
                sum=0;
        }
        
        return res;
    }
};

// O(N^2)

// int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         int res = INT_MIN;
        
//         for(int i=0;i<n;i++){
//             int sum = 0;
//             for(int j=i;j<n;j++){
//                 sum += nums[j];
//                 res = max(res, sum);
//             }
//         }
        
//         return res;
//     }