//Reverse given LL and return new head

//APPROACH1: Recursive 1
//recursive: T(n) = T(n - 1) + (n - 1) 
//solve: O(n^2) time
node *reverse_linked_list_rec(node *head)
{
    //head == NULL condition 1, head->next == NULL condition 2
    if (head == NULL || head -> next == NULL)
        return head;
    
    node* x = reverse_linked_list_rec(head -> next);
    node* temp = x;
    //If condition 2 is not used as base case, then x
    //may receive NULL, temp will also be NULL then, and
    //in the following statement if we try to access temp->next
    //program will crash
    while (temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = head;
    head -> next = NULL;
    return x;
}
//APPROACH2: Recursive 2: Make the function return a Pair
//having member pointers head and tail
//Use the tail directly to attach current head after
//the recursive call, no need to traverse
//T(n) = T(n - 1) + 1 => T(n) = n => Time : O(n)

class Pair{
    public:
    node* head;
    node* tail;
};
Pair reverseLL(node *head){
    if (head == NULL || head -> next == NULL){
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;;
    }
    Pair smallAns = reverseLL(head -> next);
    smallAns.tail -> next = head;
    head -> next = NULL;
    smallAns.tail = head;
    return smallAns;
}
node *reverse_linked_list_rec(node *head)
{
    Pair ans = reverseLL(head);
    return ans.head;
}
//APPROACH3: Recursive 3: Make use of the connection
//of current head which is basically the tail of the smallAns
//Use the tail directly to attach current head after
//the recursive call, no need to traverse
//T(n) = T(n - 1) + 1 => T(n) = n => Time : O(n)

node *reverse_linked_list_rec(node *head)
{
    if (head == NULL || head -> next == NULL)
        return head;
    
    node* x = reverse_linked_list_rec(head -> next);
    node* tail = head -> next;
    tail -> next = head;
    head -> next = NULL;
    return x;
}

//APPROACH4: Iterative
//Initialize curr as head and prev as NULL
//loop while curr is not NULL
//keep assigning next of curr to prev, 
//update prev and curr
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





