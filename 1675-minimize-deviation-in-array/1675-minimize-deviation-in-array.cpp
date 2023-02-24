class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> maxpq;
        int m = INT_MAX, diff = INT_MAX;
        for(auto num: nums){
            if(num%2!=0)
                num*=2;
            m = min(m, num);
            maxpq.push(num);
        }
        
        while(maxpq.top()%2==0){
            int mx = maxpq.top();
            maxpq.pop();
            diff = min(diff, mx-m);
            m = min(m, mx/2);
            maxpq.push(mx/2);
        }
        
        return min(diff, maxpq.top()-m);
    }
};