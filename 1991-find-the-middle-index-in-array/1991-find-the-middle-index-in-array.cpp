class Solution {
public:
    int findMiddleIndex(vector<int>& arr) {
        int rightsum = accumulate(arr.begin() , arr.end() ,0 );
        int leftSum = 0;

        for(int i=0; i<arr.size() ; i++){
            rightsum -= arr[i];

            if(rightsum == leftSum)
                return i;

            leftSum += arr[i];
        }
        return -1;
    }
};