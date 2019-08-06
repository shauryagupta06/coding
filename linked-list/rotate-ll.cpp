//Given a singly linked list of size N. The task
// is to rotate the linked list counter-clockwise by k 
//nodes, where k is a given positive integer 
//smaller than or equal to length of the linked list.

//eg. 1 2 3 4 5
//k = 3
//ans: 4 5 1 2 3

Node* rotate(Node* head, int k) {
    Node *prev = head;
    Node *curr, *tail;
    int c = 0;
    while (c < k - 1 && prev -> next != NULL){
        prev = prev -> next;
        c++;
    }
    if (prev -> next == NULL){
        return head;
    }
    curr = prev -> next;
    tail = curr;
    while (tail -> next != NULL){
        tail = tail -> next;
    }
    
    tail -> next = head;
    prev -> next = NULL;
    return curr;
}
