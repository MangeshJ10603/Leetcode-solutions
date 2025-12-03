class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* current = &dummy;
        while (current->next != nullptr && current->next->next != nullptr) {
            ListNode* first = current->next;
            ListNode* second = current->next->next;
            current->next = second;
            first->next = second->next;
            second->next = first;
            current = first;
        }
        return dummy.next;
    }
};
