class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> countMap;
        vector<int> result;

        for (int num : nums)
            countMap[num]++;

        for (const auto& entry : countMap) 
            if (entry.second > nums.size() / 3) 
                result.push_back(entry.first);

        return result;  
    }
};