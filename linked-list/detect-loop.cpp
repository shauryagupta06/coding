//Detect cycle in a LL

//Using hare turtle theorem, create two pointers: 
//hare and turtle. point both of them to head at first.
//Now, turtle moves by one position and hare moves 
//by two position. If these two pointers meet at some 
//time then loop exists. If we reach null without any 
//meeting then no loop exists.

int detectloop(Node *head) {
    Node* slow = head;
    Node* fast = head;
    while (slow != NULL && fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next ;
        
        if (slow == fast){
            return true;
        }
    }
    return false;
}