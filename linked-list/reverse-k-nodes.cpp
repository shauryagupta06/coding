int len(node* head){
    int count = 0;
    node* temp = head;
    while (temp != NULL){
        temp = temp -> next;
        count++;
    }
    return count;
}
node* rev_linkedlist_itr(node* head)
{
    node* curr = head;
    node* prev = NULL;
    node* next;
    while (curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
node* kReverse(node*head,int n)
{
    if (len(head) <= n){
        return rev_linkedlist_itr(head);
    }
    node* temp = head;
    int count = 0;
    while (count < n - 1){
        temp = temp -> next;
        count++;
    }
    node* head2 = temp -> next;
    temp -> next = NULL;
    node* x = rev_linkedlist_itr(head);
    node* y = kReverse(head2, n);
    node* t = x;
    while (t -> next != NULL){
        t = t -> next;
    }
    t -> next = y;
    return x;
}
//better complexity
node* kReverse(node*head,int n)
{
    //write your code here


     node* current = head;
     node* next = NULL;
     node* prev = NULL;
    int count = 0;   
     
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < n)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
     
   
    if (next !=  NULL)
       head->next = kReverse(next, n); 
 
 
    return prev;
}
