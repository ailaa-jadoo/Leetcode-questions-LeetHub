class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxi;
        vector<int> mini;
        
        maxi.push_back(nums[0]); mini.push_back(nums[0]);
        
        for(int i=1;i<n;i++){
            int max_sum = maxi[i-1]+nums[i];
            maxi.push_back(max(max_sum, nums[i]));
            int min_sum = mini[i-1]+nums[i];
            mini.push_back(min(min_sum, nums[i]));
        }
        
        int max_num_1 = INT_MIN, max_num_2 = INT_MAX;
        
        for(int num:maxi)
            max_num_1 = max(num, max_num_1);
        
        for(int num:mini)
            max_num_2 = min(num, max_num_2);
        
        cout<<max_num_1<<" "<<max_num_2<<" ";
        
        return max(max_num_1, abs(max_num_2)); 
    }
};