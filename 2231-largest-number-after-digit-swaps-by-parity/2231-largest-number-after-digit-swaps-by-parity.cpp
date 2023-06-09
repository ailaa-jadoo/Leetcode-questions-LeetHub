class Solution {
public:
    int largestInteger(int num) {
        string n = to_string(num);
        
        vector<char> odd, even;
        
        for(int i=0;i<n.size();i++){
            if((n[i]-'0')%2==0) 
                even.push_back(n[i]);
            else
                odd.push_back(n[i]);
        }
        
        int i=0, j=0;
        string ans;
        
        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end(), greater<int>());
        
        for(int k=0;k<n.size();k++){
            if((n[k]-'0')%2==0)
                ans+=even[i++];
            else
                ans+=odd[j++];
        }
        
        return stoi(ans);
    }
};