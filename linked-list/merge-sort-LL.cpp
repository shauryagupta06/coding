//Given a linked list, sort in ascending order, return head

//mergeTwoLLs function can be recursive or iterative

node* mergeTwoLLs(node *head1, node *head2) {
    
    if (head1 == NULL)
        return head2;
    else if (head2 == NULL)
        return head1;
    
    node* fhead = NULL;
    node* ftail = NULL;
    
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
int length(node* head){
    int len = 0;
    node* temp = head;
    while (temp != NULL){
        len ++;
        temp = temp -> next;
    }
    return len;
}
node* mergeSort(node *head) {
    if (head == NULL  || head -> next == NULL){
        return head;
    }
    node* temp = head;
    int len = length(head);
    int mid = (len - 1)/2;
    int c = 0;
    while (c < mid){
        c ++;
        temp = temp -> next;
    }
    node* head1 = head;
    node* head2 = temp -> next;
    temp -> next = NULL;
    head1 = mergeSort(head1);
    head2 = mergeSort(head2);
    head = mergeTwoLLs(head1, head2);
    return head;   
}
