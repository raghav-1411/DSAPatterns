
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL ;
        ListNode* curr = head ; 
        ListNode* Next = NULL ; 

        while(curr){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head , *fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = reverse(slow->next);
        slow->next = NULL;

        ListNode* temp1 = head , *temp2 = second;

        while(temp1 && temp2){
            if(temp1->val!=temp2->val) return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;
    }
};
