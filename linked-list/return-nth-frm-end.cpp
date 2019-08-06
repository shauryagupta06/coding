//Given a linked list consisting of L nodes and 
//given a number N. The task is to find the Nth 
//node from the end of the linked list.
//eg. 1 2 3 4 5 6, N = 2
//ans = 5

//A1: Find length len, find (len - n)th node from front
//return data

int lenOfLL(Node *head){
    int c = 0;
    while (head != NULL){
        head = head -> next;
        c++;
    }
    return c;
}
int getNthFromLast(Node *head, int n)
{
    int len = lenOfLL(head);
    if (n > len){
        return -1;
    }
    int i = len - n;
    int c = 0;
    Node* temp = head;
    while (c < i ){
        temp = temp -> next;
        c++;
    }
    /*if (temp)
        return temp -> data;
    else
        return -1;*/
    return temp -> data;
    
}
//APPROACH2: Pointers p1 and p2 point to head initially
//move p1 forward such that it point index n
//p2 points 0(head), difference in p2 and p1 = n
//move p1 and p2 together while p1 not null
//p2 gives nth node from last
//edge: if n > len of LL, p1 will reach NULL but c will 
//not be able to reach n, i.e. c < n, so return -1

int getNthFromLast(Node *head, int n)
{
    Node* p1 = head;
    Node* p2 = head;
    int c = 0;
    while (c < n && p1 != NULL){
        p1 = p1 -> next;
        c++;
    }
    if (c < n){
        return -1;
    }
    while (p1 != NULL){
            p1 = p1 -> next;
            p2 = p2 -> next;
    }
    return p2 -> data;
    
   
}
