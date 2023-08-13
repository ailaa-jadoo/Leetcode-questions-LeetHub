class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        
        if(n*m != r*c)
            return mat;
        
        vector<int> arr(n*m, 0);
        vector<vector<int>> res(r, vector<int>(c,0));
        
        int k=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                arr[k] = mat[i][j];
                k++;
            }
        
        int x=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                res[i][j] = arr[x];
                x++;
            }
        }
        
        return res;
    }
};