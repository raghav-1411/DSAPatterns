class Solution {
  public:
    int lengthOfLoop(Node *head) {
        Node* slow = head , *fast = head;
        bool check = false;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow==fast){
                check = true;
                break;
            }
        }
        
        if(!check) return 0;
        
        int count = 0 ;
        
        Node* temp = head;
        
        while(temp!=slow){
            temp = temp->next;
            slow = slow->next;
        }
        
        while(temp->next!=slow){
            count++;
            temp = temp->next;
        }
        
        return count+1;
        
    }
};
