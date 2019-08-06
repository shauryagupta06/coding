//LL1 has head1 - size m, LL2 has head2 - size n, end of LL2 points at
//one of the nodes of LL1, we need to return the data of this
//node

//Method1: Hashing
//store all nodes of head1 to NULL in map
//start from head2, find if present in map, stop
//return the data of current node: temp
//O(m + n)
#include<bits/stdc++.h>
int intersectPoint(Node* head1, Node* head2)
{
    unordered_map<Node*, int> map;
    Node* temp = head1;
    while (temp != NULL){
        map[temp]++;
        temp = temp -> next;
    }
    temp = head2;
    while (temp != NULL){
        if (map.find(temp) != map.end()){
            break;
        }
        temp = temp -> next;
    }
    return temp -> data;
}
//Method 2: Using difference of node counts:
//1) Get count of the nodes in the first list, let be c1.
//2) Get count of the nodes in the second list, let be c2.
//3) Get the difference of counts d = abs(c1 – c2)
//4) Now traverse the bigger list from the first node till 
//d nodes so that from here onwards both the lists have
//equal no of nodes.
//5) Then we can traverse both the lists in parallel 
//till we come across a common node.
//O(m + n)
int length(Node* head){
    int c = 0;
    Node* temp = head;
    while (temp != NULL){
        temp = temp -> next;
        c++;
    }
    return c;
}
int intersectPoint(Node* head1, Node* head2)
{
    int c1 = length(head1);
    int c2 = length(head2);
    int d = abs(c1 - c2);
    Node* pt1 = (c1 >= c2) ? head1 : head2;
    Node* pt2 = (c1 < c2) ? head1 : head2;
    for (int i = 0; i < d; i++){
        pt1 = pt1 -> next;
    }
    while (pt1 != pt2){
        pt1 = pt1 -> next;
        pt2 = pt2 -> next;
    }
    return pt1 -> data;
}


