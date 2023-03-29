class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        
        int maxSatis = 0;
        int suffixSum = 0;
        for(int i=satisfaction.size()-1; i>=0 and suffixSum + satisfaction[i]>0;i--){
            suffixSum += satisfaction[i];
            maxSatis += suffixSum;
        }
        
        return maxSatis;
    }
};