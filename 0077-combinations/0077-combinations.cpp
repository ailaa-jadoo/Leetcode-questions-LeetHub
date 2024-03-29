class Solution {
public:
    void backtrack(vector<vector<int>> &res, vector<int> &temp, int start, int n, int k){
        if(temp.size() == k)
            res.push_back(temp);
        else{
            for(int i=start;i<=n;i++){
                temp.push_back(i);
                backtrack(res, temp, i+1, n, k);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        
        backtrack(res, temp, 1, n, k);
        
        return res;        
    }
};