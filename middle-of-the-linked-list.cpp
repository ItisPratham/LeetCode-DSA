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
    ListNode* middleNode(ListNode* head) {
        ListNode* small_step = head;
        ListNode* large_step = head;
        while(large_step != NULL and large_step->next != NULL){
            small_step = small_step->next;
            large_step = large_step->next->next;
        }
        return small_step;
    }
};