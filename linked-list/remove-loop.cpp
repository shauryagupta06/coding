//First we need to detect loop, for algo see detect-loop.cpp
//in the same folder

//If we find a loop, RemoveLoop function is called,
//it is passes slow/fast : the node of meeting , and head
//same is the node which is the part of the loop
//We need to find the point of loop connection 
//to head, call it C, in order to break it

//Method 1: point pt2 at same and pt1 at head, keep moving
//pt1 until it comes back to the same point or 
//pt1 is reachable from pt2, if not reachable keep moving pt1
//after breaking, pt1->next will be the point C, make it NULL
//Double loop: mk times where m = dist from head to C
//k = no of nodes in loop

void removeLoop(Node* same, Node* head){
    struct Node* pt1 = head;
    struct Node* pt2;
    while(1){
        pt2 = same;
        while (pt2 -> next != same && pt2 -> next != pt1){
            pt2 = pt2 -> next;
        }
        if (pt2 -> next == pt1){
            break;
        }
        pt1 = pt1 -> next;
    }
    pt2 -> next = NULL;
}
void removeTheLoop(Node *head)
{
     struct Node* slow = head;
     struct Node* fast = head;
     while (slow != NULL && fast != NULL && fast -> next != NULL){
         slow = slow -> next;
         fast = fast -> next -> next;
         if (slow == fast){
             removeLoop(slow, head);
             return;
         }
     }
}
//Method2: count k = no. of nodes in loop by one rotation 
//place pt1 at head, place pt2 at head move k steps forward
//now pt1 is at index 0, and pt2 is at index k, so a diff.
//of k is obtained, now move pt1 and pt2 together till
//their nexts are same, here
//pt1 -> next = pt2 -> next = C
//make pt2 -> next = NULL
//One loop for finding k = k times
//one loop m + k = length of ll
//so total time = k + m + k = m + 2k

void removeLoop(Node* same, Node* head){
    struct Node* pt1 = same;
    struct Node* pt2 = same;
    int k = 1;
    while (pt1 -> next != same){
        pt1 = pt1 -> next;
        k++;
    }
    pt1 = head;
    pt2 = head;
    for (int i = 0; i < k ; i++){
        pt2 = pt2 -> next;
    }
    while (pt1 -> next != pt2 -> next){
        pt1 = pt1 -> next;
        pt2 = pt2 -> next;
    }
    pt2 -> next = NULL;
}
void removeTheLoop(Node *head)
{
     struct Node* slow = head;
     struct Node* fast = head;
     while (slow != NULL && fast != NULL && fast -> next != NULL){
         slow = slow -> next;
         fast = fast -> next -> next;
         if (slow == fast){
             removeLoop(slow, head);
             return;
         }
     }
}
//From the above method, did ypu realize that pt2 after for 
//loop points at same ? we can use this to and we do not
//need to find k

//Method 3: keep pt1 at head and pt2 at same, move
//them together and stop when both of theirs nexts point
//to the same node i.e. C
//make pt2 -> next = NULL
//only one loop = m times 

void removeLoop(Node* same, Node* head){
    struct Node* pt1 = head;
    struct Node* pt2 = same;

    while (pt1 -> next != pt2 -> next){
        pt1 = pt1 -> next;
        pt2 = pt2 -> next;
    }
    pt2 -> next = NULL;
}
void removeTheLoop(Node *head)
{
     struct Node* slow = head;
     struct Node* fast = head;
     while (slow != NULL && fast != NULL && fast -> next != NULL){
         slow = slow -> next;
         fast = fast -> next -> next;
         if (slow == fast){
             removeLoop(slow, head);
             return;
         }
     }
}

//Method4: Hashing : Maintain a map with key as Node* type
//and value as integer, keep adding curr to map and
//also maintain prev
//If repetition, make prev -> next = NULL
void removeTheLoop(Node *head)
{
    unordered_map<Node*, int> hashmap;
    Node* curr = head;
    Node* prev = NULL;
    int flag = 0;
    while (curr != NULL){
        if (hashmap.find(curr) == hashmap.end()){
            hashmap[curr]++;
            prev = curr;
            curr = curr -> next;
        }
        else{
            flag = 1;
            break;
        }
    }
    if (flag){
        prev -> next = NULL;
    }
    
}
