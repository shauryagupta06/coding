//You are given a pointer/ reference to the node which 
//is to be deleted from the linked list of N nodes. 
//The task is to delete the node. Pointer/ reference 
//to head node is not given. 

//APPROACH: 2. Since you only have pointer to the node 
//that you need to delete, you can swap the value of node 
//with the value of next node. Keep on swapping till the 
//value of the original node reaches the last node. 
//Now, you can easily delete the last node by setting
//the second last node's next to null.

// This function should delete node from linked list. The function
// may assume that node exists in linked list and is not last node
// node: reference to the node which is to be deleted
void deleteNode(Node *node)
{

    Node* prev = node;
    Node* curr = node -> next;
    Node* last = NULL;
    while(1){

        //swap adjacent node data
        int temp = prev -> data;
        prev -> data = curr -> data;
        curr -> data = temp;

        //save last node of final LL, last swap already done
        if (prev -> next -> next == NULL){
            last = prev;
            break;
        }

        //if not reached last swap, move prev and curr
        //one step forward
        prev = curr;
        curr = curr -> next;
    }
    
    last -> next = NULL;
}
