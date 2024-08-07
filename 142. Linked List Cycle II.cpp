/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool validity = false;
        while(fast != NULL and fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                validity = true;
                break;
            }
        }
        if(validity == false){
            return NULL;
        }
        else{
            ListNode* slow2 = slow->next;
            int count = 1;
            while(slow2 != slow){
                count += 1;
                slow2 = slow2->next;
            }
            ListNode* temp = head;
            ListNode* temp2 = head;
            for(int i = 0; i<count; i++){
                temp = temp->next;
            }
            while(temp2 != temp){
                temp2 = temp2->next;
                temp = temp->next;
            }
            return temp;
        }
    }
};