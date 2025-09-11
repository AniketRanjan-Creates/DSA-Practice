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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* back = dummy;
        ListNode* temp = head;
        
        while(temp){
            if(temp->next && temp->val ==temp->next->val){
                while(temp->next && temp->val==temp->next->val) {
                    temp =temp->next;
                }
                back->next = temp->next;
            }  else {
                back= back->next;
            }
            temp=temp->next;

        }
        return dummy->next;
        

        
    }
};