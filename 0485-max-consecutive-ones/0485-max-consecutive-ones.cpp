class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count =0, maxi = 0;
        for(int num : nums){
            if(num==1){
                count++;
            }
            else
                count = 0;
            
            
            maxi=max(maxi, count);
        }
        
        return maxi;
    }
};