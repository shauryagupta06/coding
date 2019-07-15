//indexing from 0
//eg. 3 -> 6 -> 1 -> 9 -> 2 -> null
//data = 100, i = 3
//ans : 3 -> 6 -> 1 -> 100 -> 9 -> 2 -> null 

//iterative
Node* insertNodeRec(Node *head, int i, int data) {
    Node* newNode = new Node(data);
    
    if (i == 0){
        newNode -> next = head;
        head = newNode;
        return head;
    }
    Node* temp = head;
    int c = 0;
    while (temp != NULL && c < i - 1){
        temp = temp->next;
        c++;
    }
    if (temp != NULL){
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
    return head;
}


//recursive
Node* insertNodeRec(Node *head, int i, int data) {
    if (head == NULL)
        return NULL;
    Node* newNode = new Node(data);
    if (i == 0){
        newNode->next = head;
        head = newNode;
        return head;
    }
    else{
        Node* x = insertNodeRec(head -> next, i - 1, data);
        head -> next = x;
        return head;
    }
}
