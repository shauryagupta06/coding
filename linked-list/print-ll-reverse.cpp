//Print a given linked list in reverse order. 
//You can’t change any pointer in the linked list, 
//i.e. you can't alter the given ll
//just print it in reverse order

//APPROACH1: iteration, O(n^2)
//find length, print last element,
//keep reducing length, traverse again from start 
//n + (n - 1) + .. + 1 = O(n^2)
void print_linkedlist_spl(node*head)
{
    int len = 0;
    node* temp = head;
    while (temp != NULL){
        len++;
        temp = temp -> next;
    }
    
    
    for (int i = len ; i >= 1; i--){
        node* t = head;
        int j = 0;
        while (j < i - 1){
            t = t -> next;
            j++;
        }
        cout<<t -> data<<" ";
    }
}

//APPROCH2: recursive O(n) : n calls only
//eg. 1 2 3 4 , we will pass 2 3 4 to recursion
//it will print 4 3 2 , now we need to print head i.e. 1
//ans : 4 3 2 1 
void print_linkedlist_spl(node*head)
{
    if (head == NULL)
        return;
    
    print_linkedlist_spl(head -> next);
    cout<<head -> data<<" ";
    
}