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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || left==right){
            return head;
        }
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev_left = dummy;

        for(int i = 0; i<left-1; i++){
            prev_left = prev_left->next;
        }
        

        ListNode* right_node = prev_left;
        for(int i = 0; i<right-left+1; i++){
            right_node = right_node->next;
        }
        ListNode* left_node = prev_left->next;
        ListNode* right_next = right_node->next;
        right_node->next = NULL;
        ListNode* back = NULL;
        ListNode* curr = left_node;
        ListNode* front = NULL;
        while(curr!=NULL){
            front = curr->next;
            curr->next = back;
            back = curr;
            curr = front;
            
        } 
        prev_left->next = back;
        left_node->next = right_next;

        head = dummy->next;
        delete dummy;
        return head;

        
    }
};