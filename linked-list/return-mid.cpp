//Problem: Given linked list, return middle node,
//if even length, return first out of two middles

//APPROACH1: find length, traverse again, stop at midpoint
//m = (len - 1)/2 , temp should point at mth index,
//indexing starts from 0
//return temp, two traversals

node* midpoint_linkedlist(node *head)
{
    int len = 0;
    node* temp = head;
    while (temp != NULL){
        len++;
        temp = temp -> next;
    }
    int mid = (len - 1)/2;
    temp = head;
    int c = 0;
    while (c < mid){
        c++;
        temp = temp -> next;
    }
    return temp;
}

//APPROACH2: only one traversal
//two pointers : slow at head, fast at head->next
//(case: even length has to return first of two middles)
//loop while fast **and** fast->next is not null
//slow will move by one step, fast will move by two
//for even l, stopping: fast-> next = null
//for odd l, stopping: fast = null
//return slow

//NOTE: in case: even length has to return second of two middles
//then slow and fast both at head, same loop stopping, 
//reason for loop stopping for even/odd will reverse

node* midpoint_linkedlist(node *head)
{
    if (head == NULL || head -> next == NULL){
        return head;
    }
    node* slow = head;
    node* fast = head -> next;
    while (fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
    
}




