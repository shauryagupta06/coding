//Given a linked list and an integer n you need 
//to find and return index where n is present in the 
//LL. Do this iteratively.

//Return -1 if n is not present in the LL.
//Indexing of nodes starts from 0.

int indexOfNIter(Node *head, int n) {
    Node* temp = head;
    int c = 0;
    while (temp != NULL && temp -> data != n){
        temp = temp -> next;
        c ++;
    }
    if (temp == NULL)
        return -1;
    return c ;
}