class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        while(a>0 or b>0 or c>0){
            int bitA = a&1;
            int bitB = b&1;
            int bitC = c&1;
            
            if(bitC==0){
                if((bitA==0 and bitB!=0) or (bitA!=0 and bitB==0))  flips++;
                if(bitA!=0 and bitB!=0) flips+=2;
            }
            else{
                if(bitA==0 and bitB==0) flips+=1;
            }
            
            a = a>>1;
            b = b>>1;
            c = c>>1;
        }
        
        return flips;
    }
};