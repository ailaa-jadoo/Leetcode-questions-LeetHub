// question similar to Count the number of subset with a given difference   dp playlist


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        
        if((target+sum)%2!=0 or (sum-target)<0)
            return 0;
        
        if(abs(target)>sum)
            return 0;
        
        //target = target<0 ? -1*target: target;  no need for this
        
        int s1 = (target+sum)/2;
        
        vector<vector<int>> t(n+1, vector<int>(s1+1, 0));
        
        t[0][0] = 1;
              
        
        for(int i=1;i<=n;i++) 
            for(int j=0;j<=s1;j++){
                if(nums[i-1]<=j)
                    t[i][j] = t[i-1][j] + t[i-1][j - nums[i-1]];
                else
                    t[i][j] = t[i-1][j];
            }
        
        return t[n][s1];
    }
};