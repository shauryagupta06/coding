//Both push and pop in O(1) time
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};
//And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; 
/* The method push to push element into the queue*/
void MyQueue:: push(int x)
{
    QueueNode* n = new QueueNode(x);
    if (front == NULL){
        front = n;
        rear = n;
        return;
    }
    rear -> next = n;
    rear = n;
}
/*The method pop which return the element
  poped out of the queue*/
int MyQueue :: pop()
{
    if (front == NULL){
        return -1;
    }   
    int ans = front -> data;
    QueueNode* temp = front;
    front = front -> next;
    if (front == NULL)
        rear = NULL;
    delete temp;
    return ans;
}
