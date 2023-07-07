class Solution {
public:
    int maximumProduct(vector<int>& arr, int k) {
        priority_queue<int> pq;
        long long prod =  1;
        int mod = 1e9+7;
        for(auto x : arr)
            pq.push(-1*x);
        
        while(k--){
            int tp = pq.top();
            pq.pop();
            tp-=1;
            pq.push(tp); 
        }
        while(!pq.empty()){
            prod = (prod*abs(pq.top()))%mod;
            pq.pop();
        }
        return prod%mod;   
    }
};