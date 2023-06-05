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
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(!list1)  
//             return list2;
//         if(!list2)  
//             return list1;
        
//         if(list1->val > list2->val)
//             swap(list1, list2);
        
//         ListNode* res = list1;
        
//         while(list1!=NULL and list2!=NULL){
//             ListNode* temp = NULL;
//             while(list1!=NULL and list1->val<=list2->val){
//                 temp = list1;
//                 list1 = list1->next;
//             }
            
//             temp->next = list2;
//             swap(list1, list2);
//         }
        
//         return res;
//     }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(!list1)  
            return list2;
        if(!list2)  
            return list1;
        
        ListNode *temp, *dummy;
        temp = new ListNode(101);
        dummy = temp;
        
        while(list1!=NULL and list2!=NULL){
            if(list1->val <= list2->val){
                dummy->next = list1;
                list1 = list1->next;
            }
            else{
                dummy->next = list2;
                list2 = list2->next;
            }
            
            dummy = dummy->next;
        }
        
        
        if(!list1)  
            dummy->next = list2;
        if(!list2)  
            dummy->next = list1;
        
        return temp->next;
    }
};