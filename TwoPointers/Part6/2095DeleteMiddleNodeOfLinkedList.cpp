class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL) return NULL;
        ListNode* slow = head ; 
        ListNode* fast = head ; 
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next ; 
            fast = fast->next->next ; 
        }
        ListNode* a = head ; 
        while(a->next!=slow){
            a = a->next ; 
        }
        a->next = a->next->next ; 
        return head;
    }
};
