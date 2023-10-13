class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>common(26,INT_MAX);
        vector<string>res;
        
        for(auto word :words){
            vector<int>count(26,0);
            
            for(auto c:word) 
                count[c-'a']++;

            for(int i=0;i<26;++i)
                common[i]=min(common[i],count[i]);
            
        }

        for(int i=0;i<26;++i)
            if(common[i]>0)
                while(common[i]--)
                    res.push_back(string(1,i+'a'));
            
            
        return res;
    }
};