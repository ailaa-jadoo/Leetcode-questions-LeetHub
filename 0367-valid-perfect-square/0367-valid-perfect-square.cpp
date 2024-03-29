class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num<2)
            return true;
        
        long left=1;
        long right = num;
        
        while(left<=right){
            long mid = left + (right-left)/2;
            long square = mid*mid;
            
            if(square == num)
                return true;
            else if(square<num)
                left = mid+1;
            else if(square>num)
                right = mid-1;
        }
        
        return false;
    }
};