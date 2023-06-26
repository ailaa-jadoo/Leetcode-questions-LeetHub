class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        long long res = 0;
        int count = 0;
        int i=0, j=costs.size()-1;
        while(count<k){
            while(pq1.size()<candidates and i<=j)
                pq1.push(costs[i++]);
            while(pq2.size()<candidates and i<=j)
                pq2.push(costs[j--]);
            
            int a = pq1.size()>0 ? pq1.top():INT_MAX;
            int b = pq2.size()>0 ? pq2.top():INT_MAX;
            
            if(a<=b){
                res += a;
                pq1.pop();
            }else{
                res += b;
                pq2.pop();
            }
            
            count++;
        }
        
        return res;
    }
};