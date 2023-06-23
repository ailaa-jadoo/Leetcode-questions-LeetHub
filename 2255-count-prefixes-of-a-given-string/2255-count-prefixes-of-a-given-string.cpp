class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        vector<string> subs;
        for(int i=0;i<s.size();i++)
            subs.push_back(s.substr(0, i+1));
        
        int count=0;
        
        for(int i=0;i<words.size();i++){
            auto it = find(subs.begin(), subs.end(), words[i]);
            if(it!=subs.end())
                count++;
        }
        
        return count;
    }
};