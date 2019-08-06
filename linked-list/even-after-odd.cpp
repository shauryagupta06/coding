//Arrange elements in a given Linked List such that, 
//all even numbers are placed after odd numbers. 
//Respective order of elements should remain same.
//eg. 1 4 5 2 
//ans 1 5 4 2

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

node* arrange_LinkedList(node* head)
{
    node* oddh = NULL;
    node* oddt = NULL;
    node* evenh = NULL;
    node* event = NULL;
    node* curr = head;
    while (curr != NULL){
        if (curr -> data % 2 == 1){
            if (oddh == NULL){
                oddh = curr;
                oddt = curr;
            }
            else{
                oddt -> next = curr;
                oddt = curr;
            }
        }
        else if (curr -> data % 2 == 0){
            if (evenh == NULL){
                evenh = curr;
                event = curr;
            }
            else{
                event -> next = curr;
                event = curr;
            }
        }
        curr = curr->next;
    }
    if (oddh == NULL){
        return evenh;
    }
    else if (evenh == NULL){
        return oddh;
    }
    oddt -> next = NULL;
    event -> next = NULL;
    oddt -> next = evenh;
    return oddh;
}
