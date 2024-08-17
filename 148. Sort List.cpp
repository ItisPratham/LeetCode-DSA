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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev;
        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode* h1 = sortList(head);
        ListNode* h2 = sortList(slow);

        return merge(h1, h2);
    }
    ListNode* merge(ListNode* head1, ListNode*head2){
        if(head1 == NULL && head2 == NULL){
            return NULL;
        }
        else if(head1 == NULL){
            return head2;
        }
        else if(head2 == NULL){
            return head1;
        }
        if(head1->val < head2->val){
            head1->next = merge(head1->next, head2);
            return head1;
        }
        else{
            head2->next = merge(head2->next, head1);
            return head2;
        }
    }
};