/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL){
            return head;
        }
        Node* curr = head;
        while(curr != NULL){
            if(curr->child != NULL){
                Node* childlist = flatten(curr->child);
                Node* temp = curr->next;
                curr->next = childlist;
                childlist->prev = curr;
                
                Node* childEnd = childlist;
                while(childEnd->next != NULL){
                    childEnd = childEnd->next;
                }
                if(temp!= NULL){
                    childEnd->next = temp;
                    temp->prev = childEnd;
                }
                curr->child = NULL;
            }
            curr = curr->next;
        }
        return head;
    }
};