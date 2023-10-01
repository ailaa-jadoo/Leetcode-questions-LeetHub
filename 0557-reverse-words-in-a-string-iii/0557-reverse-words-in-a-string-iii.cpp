class Solution {
public:
    string reverseWords(string s) {
        stringstream str(s);
        string word;
        
        string res="";
        while(str >> word){
            reverse(word.begin(), word.end());
            res+=word+' ';
        }
        
        return res.substr(0, res.size()-1);
    }
};