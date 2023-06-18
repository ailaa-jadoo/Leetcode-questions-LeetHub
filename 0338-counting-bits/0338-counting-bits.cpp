class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<=n;i++){
            int count1s =0;
            bitset<32> binaryNumber(i);
            string s = binaryNumber.to_string();
            for(int j=0;j<s.size();j++){
                if(s[j]=='1')
                    count1s++;
            }
            
            res.push_back(count1s);
        }
        
        return res;
    }
};