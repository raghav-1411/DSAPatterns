
// M1 -> By finding the length of the LinkedList which is good method but the follow up question is asked that u are not allowed to find length

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

// Without finding the length of the Linked List :-

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head , *temp = head;                

        for(int i=0 ; i<n ; i++) ptr = ptr->next;           // moving the ptr to n times
    
        if(!ptr) return head->next;                        // if the ptr becomes NULL which means the start node we have to delete

        while(ptr->next){                        // move ptr and temp each step by step (1 step at a time)
            ptr = ptr->next;
            temp = temp->next;    
        }

        temp->next = temp->next->next ;             // temp->next node will be the node which we have to delete 

        return head;
    }
};
