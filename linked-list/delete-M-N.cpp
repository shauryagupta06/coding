//Given a linked list and two integers M and N.
//Traverse the linked list such that you retain M nodes
//then delete next N nodes, continue the same until end
//of the linked list. That is, in the given linked list 
//you need to delete N nodes after every M nodes.

//eg. 1 2 3 4 5 6 7 8 -1
//M = 2
//N = 3
//ans: 1 2 6 7 

// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/

node* skipMdeleteN(node  *head, int M, int N) {
    int c1 = 1;
    int c2 = 1;
    node* t1 = head;
    node* t2 = NULL;
    
    while (true){
        while (c1 < M && t1 != NULL){
            t1 = t1 -> next;
            c1++;
        }
        if (t1 == NULL){
            return head;
        }
        t2 = t1 -> next;
        while (c2 <= N && t2 != NULL){
            node* temp = t2;
            t2 = t2 -> next;
            delete temp;
            c2++;
        }
        if (t2 == NULL){
            t1 -> next = t2;
            return head;
        }
        t1 -> next = t2;
        t1 = t2;
        c1 = 1;
        c2 = 1;
    }
}
