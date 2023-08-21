//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& image, int newColor, vector<vector<int>>& res, int iniColor, int n, int m){
        res[r][c] = newColor;
        
        int delRow[]={1, 0, -1, 0};
        int delCol[]={0, -1, 0, 1};

        for(int i=0;i<4;i++){
            int nr = r + delRow[i];
            int nc = c + delCol[i];

            if(nr>=0 and nr<n and nc>=0 and nc<m and image[nr][nc]==iniColor and res[nr][nc]!=newColor)
                dfs(nr, nc, image, newColor, res, iniColor, n, m);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> res = image;
        int iniColor = image[sr][sc];
        int n = image.size();
        int m = image[0].size();

        dfs(sr, sc, image, color, res, iniColor, n , m);

        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends