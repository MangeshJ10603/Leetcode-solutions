class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int l = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            l++;
            temp = temp->next;
        }
        int k1 = k;
        int k2 = l - k + 1;

        ListNode* node1 = head;
        while (k1 > 1) {
            node1 = node1->next;
            k1--;
        }

        ListNode* node2 = head;
        while (k2 > 1) {
            node2 = node2->next;
            k2--;
        }

        swap(node1->val, node2->val);
        return head;
    }
};
