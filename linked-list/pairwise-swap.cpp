//Given a linked list of N positive integers. 
//You need to swap elements pairwise. 
//eg1. 1 2 3 4 5 6 7
//ans: 2 1 4 3 6 5 7
//eg2. 1 2 3 4 5 6
//ans: 2 1 4 3 6 5

//A1: Recursion, send to recursion from second index
//swap first two and attach to received head

struct Node* pairwise_swap(struct Node* head)
{
    if (head == NULL || head -> next == NULL){
        return head;
    }
    
    Node* x = pairwise_swap(head -> next -> next);
    head -> next -> next = head;
    Node* t = head -> next;
    head -> next = x;
    return t;
}

//A2: Iterative
//prev takes even indices, curr takes odd indices
//before entering loop, save head
//inside loop, save next, curr should point prev
//if next is null or its next is null
//prev should point to node skipping one node
//loop should stop
//else, prev should point to node skipping two nodes
//update prev and curr

struct Node* pairwise_swap(struct Node* head)
{
    if (head == NULL || head -> next == NULL){
        return head;
    }
    Node* prev = head;
    Node* curr = head -> next;
    
    head = curr;
    
    while(1){
        Node* next = curr -> next;
        curr -> next = prev;
        
        if (next == NULL || next -> next == NULL){
            prev -> next = next;
            break;
        }
       
        prev -> next = next -> next;
        
        prev = next;
        curr = prev -> next;
    }
    return head;
    
}