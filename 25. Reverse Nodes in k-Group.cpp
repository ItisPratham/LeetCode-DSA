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
    ListNode* reversekNodes(ListNode* head, ListNode* end){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next;
        while(curr != end){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* getkthNode(ListNode* start, int k){
        while(start != NULL && k>1){
            start = start->next;
            k--;
        }
        return start;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k<2){
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupEnd = dummy;

        while(true){
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* groupEnd = getkthNode(groupStart, k);

            if(groupEnd == NULL){
                break;
            }

            ListNode* nextGroupStart = groupEnd->next;
            ListNode* reversedHead = reversekNodes(groupStart, nextGroupStart);

            prevGroupEnd->next = reversedHead;
            groupStart->next = nextGroupStart;

            prevGroupEnd = groupStart;
        }
        return dummy->next;
    }
};