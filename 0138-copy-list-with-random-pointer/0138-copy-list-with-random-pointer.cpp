/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        Node* curr = head;
        while(curr != NULL) {
            Node* copy = new Node(curr->val);
            copy->next=curr->next;
            curr->next=copy;
            curr = curr->next->next;
        }
        curr = head;
        while (curr != nullptr) {
            if (curr->random != nullptr) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        Node* org = new Node(-1);
        Node* res = org;
        curr = head;
        while(curr!=NULL){
            res->next = curr->next;
            curr->next=curr->next->next;
            res=res->next;
            curr=curr->next;
        }
        return org->next;


        
    }
};