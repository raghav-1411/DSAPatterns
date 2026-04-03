class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode *prev = NULL , *curr = head , *Next = NULL;

        while(curr){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }

        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow = head , *fast = head;

        while(fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = reverse(slow->next);
        slow->next = NULL;

        ListNode* temp1 = head , *temp2 = second;
        int ans = 0 ;

        while(temp1 && temp2){
            ans = max(ans,temp1->val+temp2->val);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return ans;
    }
};
