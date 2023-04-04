class Solution {
public:
    int partitionString(string s) {
        int res=1;
        set<char> str;
        for(auto c:s){
            if(str.find(c) != str.end()){
                res++;
                str.clear();
            }
            
            str.insert(c);
        }
        
        return res;
    }
};