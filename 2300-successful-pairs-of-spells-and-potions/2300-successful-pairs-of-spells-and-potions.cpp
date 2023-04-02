class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res;
        
        sort(potions.begin(), potions.end());
        int m = potions.size();
        int maxStrenPotion = potions[m-1];
        
        for(auto& spell : spells){
            
            long long minStrenPotion = ceil((1.0 * success)/spell);
            
            if(minStrenPotion > maxStrenPotion){
                res.push_back(0);
                continue;
            }
            
            int index = lower_bound(potions.begin(), potions.end(), minStrenPotion) - potions.begin();
            res.push_back(m-index);
        }
        
        return res;
    }
};