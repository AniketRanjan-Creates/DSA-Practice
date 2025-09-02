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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast=fast->next->next;
        }
        ListNode* curr = slow;
        ListNode* prev = NULL;
        ListNode* front = NULL;
        while(curr!=NULL){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr=front;
        }
        ListNode* l1 = head;
        ListNode* l2 = prev;
        while(l2 != NULL) {
            if(l1->val != l2->val) return false;
            l1 = l1->next;
            l2=l2->next;
        
        }
        return true;

    }
};