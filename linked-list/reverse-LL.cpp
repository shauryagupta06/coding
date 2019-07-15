//Reverse given LL and return new head

//recursive: T(n) = T(n - 1) + (n - 1) 
//solve: O(n^2) time
node *reverse_linked_list_rec(node *head)
{
    if (head == NULL || head -> next == NULL)
        return head;
    
    node* x = reverse_linked_list_rec(head -> next);
    node* temp = x;
    while (temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = head;
    head -> next = NULL;
    return x;
}

