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
        if(head==NULL) return head;
       
        ListNode* temp = head;
        int length = 1;
        while(temp != NULL && temp->next!=NULL){
            temp=temp->next;
            length++;
        }
        n = length-n;
        if (n == 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        temp = head;
        for(int i = 1; i<n; i++){
            temp = temp->next;
        }
        ListNode* dnode = temp->next;
        temp->next = dnode->next;
        delete dnode;
        return head;

        
    }
};