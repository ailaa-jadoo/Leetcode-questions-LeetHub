/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mHead;
    
    Solution(ListNode* head) {
        mHead = head;
    }
    
    int getRandom() {
        ListNode* curr = mHead;
        int res=0,n=1;
        while(curr){
            if(rand()%n==0)
                res=curr->val;
            
            n++;
            curr= curr->next;
        }
        
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */