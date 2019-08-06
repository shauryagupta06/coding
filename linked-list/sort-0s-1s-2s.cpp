//Given a linked list of N nodes where nodes can 
//contain values 0s, 1s and 2s only. The task is to 
//segregate 0s, 1s and 2s linked list such that all 
//zeros segregate to headside, 2s at the end of the 
//linked list and 1s in the mid of 0s and 2s.

//Iterate through the linked list. Maintain 3 pointers 
//named zero, one and two fro head and three 
//for tail to point to current ending nodes of linked lists 
//containing 0, 1, and 2 respectively. For every traversed 
//node, we attach it to the end of its corresponding list. 
//Finally we link all three lists. 

Node* segregate(Node *head) {
    
    Node* oneh = NULL;
    Node* onet = NULL;
    Node* twoh = NULL;
    Node* twot = NULL;
    Node* zeroh = NULL;
    Node* zerot = NULL;
    Node* temp = head;
    while (temp != NULL){
        if (temp -> data == 0){
            if (zeroh == NULL){
                zeroh = temp;
                zerot = temp;
            }
            else{
                zerot -> next = temp;
                zerot = temp;
            }
        }
        else if (temp -> data == 1){
            if (oneh == NULL){
                oneh = temp;
                onet = temp;
            }
            else{
                onet -> next = temp;
                onet = temp;
            }
        }
        else if (temp -> data == 2){
            if (twoh == NULL){
                twoh = temp;
                twot = temp;
            }
            else{
                twot -> next = temp;
                twot = temp;
            }
        }
        temp = temp -> next;
    }
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    if (zerot != NULL)
        zerot -> next = NULL;
    else 
        flag1 = 1;
        
    if (onet != NULL)
        onet -> next = NULL;
    else 
        flag2 = 1;
        
    if (twot != NULL)
        twot -> next = NULL;
    else 
        flag3 = 1;
        
    int sum = flag1 + flag2 + flag3;
    if (sum == 0){
        zerot -> next = oneh;
        onet -> next = twoh;
        return zeroh;
    }
    if (sum == 1){
        if (flag1){
            onet -> next = twoh;
            return oneh;
        }
        else if (flag2){
            zerot -> next = twoh;
            return zeroh;
        }
        else{
            zerot -> next = oneh;
            return zeroh;
        }
    }
    if (sum == 2){
        if (!flag1){
            return oneh;
        }
        else if (!flag2){
            return oneh;
        }
        else{
            return twoh;
        }
    }
    if (sum == 3){
        return NULL;
    }
}

//shorter code
//assuming a constructor in Node class
Node* segregate(Node *head) {
    if (!head || !(head->next))
        return head;
  
    // Create three dummy nodes to point to 
    // beginning of three linked lists. These 
    // dummy nodes are created to avoid many 
    // null checks. 
    Node* zeroD = new Node(0); 
    Node* oneD = new Node(0); 
    Node* twoD = new Node(0); 
  
    // Initialize current pointers for three 
    // lists and whole list. 
    Node* zero = zeroD, *one = oneD, *two = twoD; 
  
    // Traverse list 
    Node* curr = head; 
    while (curr) { 
        if (curr->data == 0) { 
            zero->next = curr; 
            zero = zero->next; 
            curr = curr->next; 
        } else if (curr->data == 1) { 
            one->next = curr; 
            one = one->next; 
            curr = curr->next; 
        } else { 
            two->next = curr; 
            two = two->next; 
            curr = curr->next; 
        } 
    } 
  
    // Attach three lists 
    zero->next = (oneD->next) ? (oneD->next) : (twoD->next); 
    one->next = twoD->next; 
    two->next = NULL; 
  
    // Updated head 
    head = zeroD->next; 
  
    return head;
}
