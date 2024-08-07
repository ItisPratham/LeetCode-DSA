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
    bool hasCycle(ListNode *head) {
        ListNode* small_step = head;
        ListNode* large_step = head;
        while(large_step != NULL and large_step->next != NULL){
            large_step = large_step->next->next;
            small_step = small_step->next;
            if(large_step == small_step){
                return true;
            }
        }
        return false;
    }
};