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
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* temp;
        while (head) {
            // Keep the next node.
             temp = head->next;
            // reverse the link
            head->next = prev;
            // Update the previous node and the current node.
            prev = head;
            head = temp;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r1 = reverseList(l1);
        ListNode* r2 = reverseList(l2);
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        
        int carry=0;
        
        while(r1!=NULL or r2!=NULL or carry){
            int sum=0;
            
            if(r1!=NULL){
                sum += r1->val;
                r1 = r1->next;
            }
            
            if(r2!=NULL){
                sum += r2->val;
                r2 = r2->next;
            }
            
            sum += carry;
            carry = sum/10;
            ListNode* newNode = new ListNode(sum%10);
            temp->next = newNode;
            temp = temp->next;
        }
        
        return reverseList(dummy->next);
    }
};