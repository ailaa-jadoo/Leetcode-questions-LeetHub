class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, int> umap;
        int target=0;
        for(int i=0; i<nums.size(); i++)
            target=max(target, ++umap[nums[i]%space]);

        int res =INT_MAX;
        
        for(int i=0; i<nums.size(); i++)
            if(umap[nums[i]%space]==target)
                res=min(res, nums[i]);
            
        return res;
    }
};