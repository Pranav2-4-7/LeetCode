/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    // 1. Using ListNode exactly as LeetCode defined it
    struct ListNode* prev = NULL;
    struct ListNode* current = head; 
    struct ListNode* next = NULL;
    
    // 2. The standard reversal loop
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    // 3. Return the new head of the reversed list (which is now 'prev')
    return prev; 
}