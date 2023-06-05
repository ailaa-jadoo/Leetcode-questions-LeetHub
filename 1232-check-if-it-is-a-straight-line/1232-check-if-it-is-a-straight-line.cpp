class Solution {
public:    
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int currDelX = coordinates[1][0]-coordinates[0][0];
        int currDelY = coordinates[1][1]-coordinates[0][1];
        
//         int n = coordinates.size();
        
//         if(n == 2)
//             return true;
        
        for(int i=1;i<coordinates.size()-1;i++){
            int DelX = coordinates[i+1][0]-coordinates[i][0];
            int DelY = coordinates[i+1][1]-coordinates[i][1];
            
            if(currDelX*DelY != currDelY*DelX)
                return false;
        }
        
        return true;
    }
};