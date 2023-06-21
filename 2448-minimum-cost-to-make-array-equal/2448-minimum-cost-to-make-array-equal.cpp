class Solution {
public:
    public:
        long long f(vector<int>& A, vector<int>& cost, int x) {
            long long res = 0;
            for (int i = 0; i < A.size(); ++i)
                res += 1L * abs(A[i] - x) * cost[i];
            return res;
        }
    
        long long minCost(vector<int>& nums, vector<int>& cost) {
            long long total=0;
            long long sum=0;
            long long median;
            
            vector<pair<int,int>> v;
            
            for(int i=0;i<nums.size();i++)
                v.push_back({nums[i],cost[i]});
            
            sort(v.begin(),v.end());
            for(int i=0;i<cost.size();i++)
                sum+=v[i].second;
            
            int i=0;
            while(total<(sum+1)/2 && i<nums.size()){
                total+=v[i].second;
                median=v[i].first;
                i++;
            }
            
            return f(nums,cost,median);
    }
};