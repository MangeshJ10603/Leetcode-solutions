class Solution {
public:
    ListNode* solve(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr!=nullptr){
            ListNode* nextptr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextptr;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr and fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* reversed=solve(slow);
        int maxi=0;
        ListNode* p1=head;
        ListNode* p2=reversed;
        while(p2!=nullptr){
            maxi=max(maxi,p1->val+p2->val);
            p1=p1->next;
            p2=p2->next;
        }
        return maxi;
    }
};
