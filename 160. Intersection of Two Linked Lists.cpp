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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int countA = 0;
        int countB = 0;
        while(tempA != NULL){
            countA++;
            tempA = tempA->next;
        }
        while(tempB != NULL){
            countB++;
            tempB = tempB->next;
        }
        tempA = headA;
        tempB = headB;
        if(countA > countB){
            while(countA > countB){
                tempA = tempA->next;
                countA--;
            }
        }
        else{
            while(countB > countA){
                tempB = tempB->next;
                countB--;
            }
        }
        while(tempA != NULL){
            if(tempA == tempB){
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return NULL;
    }
};