class Solution {
public:
//     int digiSum(int n){
//         string ch = to_string(n);
//         int sum = 0;
//         for(int i=0;i<ch.size();i++){
//             sum = sum + (ch[i]-'0');
//         }
        
//         return sum;
//     }
    
    int digiSum(int n){
        int sum = 0;
        while(n){
            sum += n%10;
            n=n/10;
        }
        
        return sum;
    }
    
    int countBalls(int lowLimit, int highLimit) {
        vector<int> boxes(60, 0);
        int maxi=INT_MIN;
        
        for(int i=lowLimit;i<=highLimit;i++)
            boxes[digiSum(i)]++;
        
        for(int box:boxes)
            maxi = max(maxi, box);
        
        return maxi;
    }
};