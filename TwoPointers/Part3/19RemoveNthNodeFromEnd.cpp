class Solution {
public:
    int sizecount(ListNode* head){
        int size = 0 ;
        while(head!=NULL){
            size++;
            head = head->next;
        }
        return size;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int a = sizecount(head);
        ListNode* temp = head;
        if(a==n){
            head = head->next;
            return head;
        }
        for(int i=1 ; i<a-n ; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};
