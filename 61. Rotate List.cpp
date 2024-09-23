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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next){
            return head;
        }
        
        int l = 1;
        ListNode* last = head;
        
        while(last->next){
            l++;
            last = last->next;
        }

        k = k%l;
        
        if(k == 0){
            return head;
        }
        
        ListNode* newTail = head;
        
        for(int i = 0; i < l-k-1; i++){
            newTail = newTail->next;
        }
        
        ListNode* newHead = newTail->next;

        newTail->next = nullptr;
        last->next = head;
        
        return newHead;
    }
};