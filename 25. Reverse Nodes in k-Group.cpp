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
private:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* next;
        while(head != NULL){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL){
            return head;
        }
        int i = 0;
        ListNode* temp = head;
        ListNode* curr;
        ListNode* prev;
        ListNode* start = head;
        while(temp!= NULL){
            if((i+1)%k == 0){
                curr = temp;
                temp = temp->next;
                curr->next = NULL;
                curr = reverse(start);
                if((i+1) == k){
                    head = curr;
                }
                else{
                    prev->next = curr;
                }
                start = temp;
                while(curr->next != NULL){
                    curr = curr->next;
                }
                prev = curr;
                curr->next = temp;
            }
            else{
                temp = temp->next;
            }
            i++;
        }
        return head;
    }
};