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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* temp = head;
        
        int cnt = 0;
        
        while(temp){
            temp = temp->next;
            cnt++;
        }
        
        if(cnt == n)
            return head->next;
        
        for(int i=0;i<cnt-n-1;i++)
            first = first->next;
        
        first->next = first->next->next;
        
        return head;
    }
};