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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head; 

        while(fast!= nullptr && fast->next != nullptr){
            slow = slow->next; 
            fast = fast->next->next;


        }

        ListNode* secondhalf = slow->next;
        slow->next = nullptr;


        ListNode* prev = nullptr;
        ListNode* curr = secondhalf;
        ListNode* next = nullptr;

        while(curr!=nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* p1= head;
        ListNode* p2 = prev;
        while(p2 != nullptr){
            ListNode* next1 = p1->next;
            ListNode* next2 = p2->next;

            p1->next = p2;
            p2->next = next1;

            p1 = next1;
            p2 = next2;

        }
    }
};