class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> m;
        for(auto n:nums2){
            while(!st.empty() and st.top()<n){
                m[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }
        
        vector<int> res;
        for(auto n:nums1)
            res.push_back(m.count(n)? m[n]:-1);
        
        return res;
    }
};

// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> res(nums1.size());
//         for(int i=0;i<nums1.size();i++){
//             auto it = find(nums2.begin(), nums2.end(), nums1[i]);
//             int idx = distance(nums2.begin(), it);
//             for(int j=idx;j<nums2.size();j++){
//                 if(nums2[j]>nums1[i]){
//                     res[i] = nums2[j];
//                     break;
//                 }
//                 else
//                     res[i] = -1;
//             }
//         }
        
//         return res;
//     }
// };