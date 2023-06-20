class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        for(int i=0;i<k;i++)
            sum+=nums[i];
        
        double maxAvg = sum/k;
        
        for(int j=k;j<nums.size();j++){
            sum += nums[j] - nums[j-k];
            double newAvg = sum/k;
            maxAvg = max(maxAvg, newAvg);
        }
        
        return maxAvg;
    }
};