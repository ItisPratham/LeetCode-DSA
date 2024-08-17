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
        if(head == NULL || head->next == NULL){
            return true;
        }

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
        while(fast != NULL && fast->next != NULL){
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        prev->next = NULL;
        ListNode* head2 = reverseLL(slow);
        while(head != NULL && head2 != NULL){
            if(head->val != head2->val){
                return false;
            }
            head = head->next;
            head2 = head2->next;
        }
        return true;

    }
    ListNode* reverseLL(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        if(curr == NULL){
            return curr;
        }
        ListNode* nnext;
        while(curr != NULL){
            nnext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nnext;
        }
        return prev;
    }
};