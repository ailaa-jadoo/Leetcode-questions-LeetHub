class Solution {
public:
    int longestString(int x, int y, int z) {
        if(x==y)
            return 2 * (x + y + z);
        
        // matching XY pairs + extra element from X or Y + Z
        return 2 * (min(x, y) + (min(x, y) + 1) + z);
    }
};