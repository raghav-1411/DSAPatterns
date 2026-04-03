class Solution {
  public:
    pair<Node *, Node *> splitList(struct Node *head) {
        Node * slow = head , *fast = head;
        
        while(fast->next!=head && fast->next->next!=head){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node* second = slow->next;
        slow->next = head;
        
        Node* temp = second;
        
        while(temp->next!=head) temp = temp->next;
        
        temp->next = second;
        
        return {head,second};
        
    }
};
