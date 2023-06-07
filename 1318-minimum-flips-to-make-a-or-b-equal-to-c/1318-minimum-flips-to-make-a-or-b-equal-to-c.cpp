class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        while(a>0 or b>0 or c>0){
            
            // Getting last bit of each number from its binary equivalent
            int bitA = a&1;
            int bitB = b&1;
            int bitC = c&1;
            
            // agar c 0 chahiye to dono bit(a,b) ko zero hona hi padega uss hisab se flip count kare h
            if(bitC==0){
                if((bitA==0 and bitB!=0) or (bitA!=0 and bitB==0))  flips++;
                if(bitA!=0 and bitB!=0) flips+=2;
            }
            // agar c 1 chahiye to ya to dono bit(a,b) 1 ho ya koi ek bhi ho to bhi chalega to minimum operation ke hisab se 1 flip ki hi requirement h
            else{
                if(bitA==0 and bitB==0) flips+=1;
            }
            
            // ye shifting kar di h last bit uda di ab baki ki bits check karenge agle iteration main
            a = a>>1;
            b = b>>1;
            c = c>>1;
        }
        
        return flips;
    }
};