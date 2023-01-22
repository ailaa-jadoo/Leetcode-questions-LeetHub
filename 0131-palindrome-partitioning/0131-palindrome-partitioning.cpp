class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        func(0, s, path, res);
        return res;
    }
    
    void func(int indx, string s, vector<string> &path, vector<vector<string>> &res){
        if(indx == s.size()){
            res.push_back(path);
            return;
        }
        
        for(int i = indx; i<s.size();++i){
            if(isPalindrome(s, indx, i)){
                path.push_back(s.substr(indx, i-indx+1));
                func(i+1, s, path, res);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++] != s[end--])
                return false;
        }
        
        return true;
    }
};