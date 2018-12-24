/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) return l2;
        if(l2=nullptr) return l1;

        ListNode * mergedHead=nullptr;

        if(l1->val<l2->val){
            mergedHead= l1;
            mergedHead->next = mergeTwoLists(l1->next, l2); 
        }else{
            mergedHead= l2;
            mergedHead->next = mergeTwoLists(l1, l2->next); 
        }
       return mergedHead; 
    }
};