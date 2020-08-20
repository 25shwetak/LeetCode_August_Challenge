/*

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

*/

class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == NULL
        || head->next == NULL
        || head->next->next == NULL) {
            return;
        }
        
        ListNode *mid = head;
        ListNode *end = head;
        while (end->next != NULL) {
            mid = mid->next;
            end = end->next;
            if (end->next == NULL) {
                break;
            } else {
                end = end->next;
            }
        }
        
        ListNode *current = mid->next;
        ListNode *prev = mid;
        mid->next = NULL;
        while (current != NULL) {
            ListNode *tmp = current->next;
            current->next = prev;
            prev = current;
            current = tmp;
        }

        current = head;
        ListNode *leftCurrent = head->next;
        ListNode *rightCurrent = prev;
        bool isLeft = false;
        while (leftCurrent != mid && rightCurrent != NULL) {
            if (isLeft) {
                current->next = leftCurrent;
                leftCurrent = leftCurrent->next;
            } else {
                current->next = rightCurrent;
                rightCurrent = rightCurrent->next;
            }
            current = current->next;
            isLeft = !isLeft;
        }
        if (leftCurrent != mid) {
            current->next = leftCurrent;
            while (leftCurrent != mid) {
                prev = leftCurrent;
                leftCurrent = leftCurrent->next;
            }
            prev->next = NULL;
        }
        if (rightCurrent != NULL) {
            current->next = rightCurrent;
        }
    }
};
