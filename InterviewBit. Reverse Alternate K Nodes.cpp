/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 ListNode* reverse(ListNode* head, ListNode* end){
     ListNode* prev = NULL;
     ListNode* next;
     ListNode* curr = head;
     while(curr != end){
         next = curr->next;
         curr->next = prev;
         prev = curr;
         curr = next;
     }
     return prev;
 }
 
 ListNode* getKthNode(ListNode* start, int k){
     while(k>1 and start != NULL){
         start = start->next;
         k--;
     }
     return start;
 }
 
ListNode* Solution::solve(ListNode* A, int B) {
    if(A == NULL || B <= 1){
        return A;
    }
    ListNode* dummy = new ListNode(0);
    dummy->next = A;
    ListNode* prev_group_end = dummy;
    bool flag = true;
    
    while(true){
        ListNode* group_start = prev_group_end->next;
        ListNode* group_end = getKthNode(group_start, B);
        
        if(group_end == NULL){
            break;
        }
        
        ListNode* next_group_start = group_end->next;
        
        if(flag){
            ListNode* reversed_head = reverse(group_start, next_group_start);
            
            prev_group_end->next = reversed_head;
            group_start->next = next_group_start;
            
            prev_group_end = group_start;
        }
        else{
            prev_group_end->next = group_start;
            group_end->next = next_group_start;
            prev_group_end = group_end;

        }
        
        flag = !flag;
    }
    return dummy->next;
}