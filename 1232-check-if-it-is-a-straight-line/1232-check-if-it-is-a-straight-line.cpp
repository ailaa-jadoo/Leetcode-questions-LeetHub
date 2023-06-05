class Solution {
public:
    
    bool check(vector<int>& coord1, vector<int>& coord2, int currDelX, int currDelY){
        int DelX = coord2[0]-coord1[0];
        int DelY = coord2[1]-coord1[1];
        
        return (DelX == currDelX) and (DelY == currDelY);
    }
    
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int currDelX = coordinates[1][0]-coordinates[0][0];
        int currDelY = coordinates[1][1]-coordinates[0][1];
        
        int n = coordinates.size();
        
        if(n == 2)
            return true;
        
        for(int i=1;i<n-1;i++){
            int DelX = coordinates[i+1][0]-coordinates[i][0];
            int DelY = coordinates[i+1][1]-coordinates[i][1];
            
            if(currDelX*DelY != currDelY*DelX)
                return false;
        }
        
        return true;
    }
};