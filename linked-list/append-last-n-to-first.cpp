//Given a linked list and an integer n, 
//append the last n elements of the LL to front.
//Indexing starts from 0. You don't need to print 
//the elements, just update the elements and 
//return the head of updated LL.
//Assume given n will be smaller than length of LL.

//eg. given : 1 2 3 4 5 -1, n = 3
//ans: 3 4 5 1 2

node* append_LinkedList(node* head,int n)
{
    node* temp = head;
    node* last = head;
    int l = 1;
    int c = 0;
    while (last -> next != NULL){
        l++;
        last = last -> next;
    }
    int i = l - n - 1;
    while (c < i){
        temp = temp -> next;
        c++;
    }
    last -> next = head;
    head = temp -> next;
    temp -> next = NULL;
    return head;   
}