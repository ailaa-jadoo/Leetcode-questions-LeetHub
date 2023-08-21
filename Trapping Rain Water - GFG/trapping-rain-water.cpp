//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int height[], int n){
        // code here
        // int n = height.size();
        vector<int> preMax(n);
        vector<int> sufMax(n);

        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi, height[i]);
            preMax[i] = maxi;
        }
        
        maxi = INT_MIN;
        for(int i=n-1;i>=0;i--){
            maxi = max(maxi, height[i]);
            sufMax[i] = maxi;
        }

        long long res = 0;
        for(int i=0;i<n;i++){
            res +=  min(preMax[i], sufMax[i]) - height[i];
        }

        return res;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends