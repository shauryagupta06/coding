//Given a sorted linked list in ascending order.
//Eliminate duplicates from the given LL, 
//such that output LL contains only unique elements.
//return updated head

//eg. 1 2 3 3 3 4 4 5 5 5 7 -1
//ans: 1 2 3 4 5 7


//APPROACH: maintain two pointers t1 and t2
//Initially, t1 is first node, t2 is second
//loop till t2 is null
//If both have different data, connect t1 to t2
//then, point t1 to t2 and move t2 one step forward
//if both have same data, delete current t2 
//and move t2 forward by one step
//after coming out of loop, connect t1 to t2

node* eliminate_duplicate(node* head)
{   
    if (head == NULL || head -> next == NULL)
        return head;
    
    node* t1 = head;
    node* t2 = head -> next;
    
    while (t2 != NULL){
        if (t1 -> data != t2 -> data){
            t1 -> next = t2;
            t1 = t2;
            t2 = t2 -> next;
        }
        else{
            node* a = t2;
            t2 = t2 -> next;
            delete a;
        }
    }
    t1 -> next = t2;
    return head;
}
