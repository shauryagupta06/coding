//Given two sorted LLs (ascending)
//merge them into one sorted LL
//return head

//iterative
Node* mergeTwoLLs(Node *head1, Node *head2) {
    
    if (head1 == NULL)
        return head2;
    else if (head2 == NULL)
        return head1;
    
    Node* fhead = NULL;
    Node* ftail = NULL;
    
    if (head1 -> data < head2 -> data){
        fhead = head1;
        ftail = head1;
        head1 = head1 -> next;
    }
    else{
        fhead = head2;
        ftail = head2;
        head2 = head2 -> next;
    }
    
    while (head1 != NULL && head2 != NULL){
        if (head1 -> data < head2 -> data){
            ftail -> next = head1;
            ftail = head1;
            //OR tail = tail -> next
            head1 = head1 -> next;
        }
        else{
            ftail -> next = head2;
            ftail = head2;
            //OR tail = tail -> next
            head2 = head2 -> next;
        }
    }
    
    //Note: tail is just used as a temporary storage variable
    //after one of these two steps, tail won't pint on the actual tail of the final LL
    if (head1 == NULL){
        ftail -> next = head2;
    }
    if (head2 == NULL){
        ftail -> next = head1;
    }
    return fhead;
}

//recursive
//we compare two given heads, find smaller one and
//make it fhead, smaller head moves one step forward
//call recursion on updated heads(one full LL and other 
//LL reduced by 1)
//attach fhead with the received head

Node* mergeTwoLLs(Node *head1, Node *head2) {
    
    if (head1 == NULL)
        return head2;
    else if (head2 == NULL)
        return head1;
    
    Node* fhead = NULL;
    if (head1 -> data < head2 -> data){
        fhead = head1;
        head1 = head1 -> next;
    }
    else{
        fhead = head2;
        head2 = head2 -> next;
    }
    Node* x = mergeTwoLLs(head1, head2);
    fhead -> next = x;
    return fhead;
}

