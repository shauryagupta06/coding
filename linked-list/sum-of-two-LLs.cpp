//Given two numbers represented by two linked lists 
//of size N and M. The task is to return a sum list. 
//The sum list which is a linked list representation 
//of addition of two input numbers.

//eg. 4 5
//and   3 4 5
//ans: 0 9 3
//5->4 // linked list repsentation of 45.
//5->4->3 // linked list representation of 345.
//0->9 ->3 // linked list representation of 390 resultant LL

//Method1: Iterative , perform digit by digit sum
//If one linked list end, perform same with other
//If a carry is left , insert a node with value 1 at end

Node* addTwoLists(Node* first, Node* second) {
    if (first == NULL){
        return second;
    }
    else if (second == NULL){
        return first;
    }
    
    Node* t1 = first;
    Node* t2 = second;
    Node* fhead = NULL;
    Node* ftail = NULL;
    int c = 0;
    while (t1 != NULL && t2 != NULL){
        int s = t1->data + t2->data + c;
        int dig = s % 10;
        c = s / 10;
        Node* newNode = new Node(dig);
        if (fhead == NULL){
            fhead = newNode;
            ftail = newNode;
        }
        else {
            ftail -> next = newNode;
            ftail = ftail -> next;
        }
        t1 = t1 -> next;
        t2 = t2 -> next;
    }
    while (t1 != NULL){
        int s = t1 -> data + c;
        int dig = s % 10;
        c = s / 10;
        Node* newNode = new Node(dig);
        ftail -> next = newNode;
        ftail = ftail -> next;
        t1 = t1 -> next;
    }
    while (t2 != NULL){
        int s = t2 -> data + c;
        int dig = s % 10;
        c = s / 10;
        Node* newNode = new Node(dig);
        ftail -> next = newNode;
        ftail = ftail -> next;
        t2 = t2 -> next;
    }
    if (c == 1){
        Node* carry = new Node(1);
        ftail -> next = carry;
        ftail = ftail -> next;
    }
    return fhead;
}
//Method 2: Recursive: 
 
