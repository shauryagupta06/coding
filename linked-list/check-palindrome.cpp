//Given a singly linked list of size N of integers.
//The task is to check if the given linked list is 
//palindrome or not.

//APPROACH1: O(n) : Two Traversals 
//traverse till temp, push data to stack
//head2 will be next to temp
//if len is odd, head2 will move one step forward
//Till head reaches null, check if data of head2
//and top of stack are equal, pop top from stack
//if not equal, just return false
//If we come out of loop , means all data was equal,
//return true

int length(Node* head){
    int c = 0;
    while (head != NULL){
        c++;
        head = head -> next;
    }
    return c;
}
bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL){
        return true;
    }
    int len = length(head);
    stack<int> s;
    int i = (len/2) - 1;
    Node* temp = head;
    int c = 0;
    while (c < i ){
        s.push(temp -> data);
        temp = temp -> next;
        c++;
    }
    s.push(temp -> data);
    Node* head2 = temp -> next;
    
    if (len%2 == 1){
        head2 = head2 -> next;
    }
    while (head2 != NULL){
        if (head2 -> data != s.top()){
            return false;
        }
        s.pop();
        head2 = head2 -> next;
    }
    return true;
}
//APPROACH2 : Reverse first half, get head and check equality
//of data with other till one the two halves finish
//O(n) time
