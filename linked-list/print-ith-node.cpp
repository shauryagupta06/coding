void printIthNode(Node *head, int i) {
    Node *temp = head;
    int c = 0;
    int idata;
    while (temp != NULL && c < i ){
        c++;
        temp = temp->next;
    }
    if (temp != NULL)
        cout<<temp->data;
}