class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head , *fast = head;
        bool check = false;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast){
                check = true;
                break;
            }
        }
        if(!check) return NULL;

        ListNode* temp = head;

        while(slow!=temp){
            slow = slow->next;
            temp = temp->next;
        }
        return temp;
    }
};
