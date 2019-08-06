//Here we use top as head of linked list of stack
//We will push at the head and also pop from the head
//Both operations in O(1) time

//The structure of the node of the stack is
struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int a)
    {
        data = a;
        next = NULL;
    }
};
// And this is structure of MyStack
class MyStack {
private:
StackNode *top;
public :
    void push(int);
    int pop();
    MyStack()
    {
        top = NULL;
    }
};
/* The method push to push element
   into the stack */
void MyStack ::push(int x) {
    StackNode* n = new StackNode(x);
    if (top == NULL){
        top = n;
        return;
    }
    n -> next = top;
    top = n;
}
/* The method pop which return the element
  poped out of the stack*/
int MyStack ::pop() {
    if (top == NULL){
        return -1;
    }
    int ans = top -> data;
    StackNode* temp = top;
    top = top -> next;
    delete temp;
    return ans;
}
