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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        ListNode* temp = head;
        int length = 1;
        while(temp->next != NULL){
            temp=temp->next;
            length++;
        }
        temp->next = head;
        k = k % length;
        int steps  = length-k;
        ListNode* new_tail = head;
        for(int i = 1; i<steps; i++){
            new_tail = new_tail->next;
        }
        ListNode* new_head = new_tail->next;
        new_tail->next = NULL;
        return new_head;
    }
};