//Given a linked list and an integer n you need
// to find and return index where n is present in
// the LL. Do this recursively.
//Return -1 if n is not present in the LL.
//Indexing of nodes starts from 0.

int indexOfNRecursive(Node *head, int n) {
    if (head == NULL){
        return -1;
    }
    if (head -> data == n){
        return 0;
    }
    int ans = indexOfNRecursive(head -> next, n) ;
    if (ans == -1 ){
        return -1 ;
    }
    else{
        return ans + 1;
    }
}
