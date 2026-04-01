// Brute Force Approach -> 

class Solution {
public:
    unordered_set<int> s;
    Node* lowestCommonAncestor(Node* p, Node * q) {
        while(p->parent){
            s.insert(p->val);
            p = p->parent;
        }
        while(q->parent){
            if(s.find(q->val)!=s.end()) return q;
            q = q->parent;
        }
        return p;
    }
};

// Optimised Approach -> (Converting the problem of BT into Linked List then finding the intersection of both LL without finding its size

// very very good approadch !!

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* temp1 = p ;
        Node* temp2 = q;

        while(temp1!=temp2){
            temp1 = (temp1==NULL) ? q : temp1->parent;
            temp2 = (temp2==NULL) ? p : temp2->parent;
        }

        return temp1;
    }
};
