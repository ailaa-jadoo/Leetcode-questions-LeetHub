class Solution {
public:
    string removeStars(string s) {
        string res="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='*')
                res.pop_back();
            else
                res.push_back(s[i]);
        }
        
        return res;
    }
};


//     string removeStars(string s) {
//         stack<char> st;
//         for(int i=0;i<s.size();i++){
//             if(s[i]=='*')
//                 st.pop();
//             else
//                 st.push(s[i]);
//         }
        
//         string res="";
        
//         while(!st.empty()){
//             res.push_back(st.top());
//             st.pop();
//         }
        
//         reverse(res.begin(), res.end());
        
//         return res;
//     }
// };