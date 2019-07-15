//iterative
Node* deleteNode(Node *head, int i) {
    if (head == NULL){
        return head;
    }
    if (i == 0){
        return head->next;
    }
    Node* temp = head;
    int count = 0;
    while (temp != NULL && count < i - 1){
        temp = temp -> next;
        count ++;
    }
    if (temp == NULL){
        return head;
    }
    if (temp->next != NULL){
        temp->next = temp->next->next;
    }
    
    return head;
}

//recursive
Node* deleteNodeRec(Node *head, int i) {
    if (head == NULL)
        return NULL;
    
    if (i == 0){
        Node* a = head;
        head = head -> next;
        delete a;
        return head;
    }
    else{
        Node* x = deleteNodeRec(head -> next, i - 1);
        head -> next = x;
        return head;
    }
    
}