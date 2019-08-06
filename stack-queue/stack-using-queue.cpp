/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */
/* The method push to push element into the stack */
void QueueStack :: push(int x)
{
    q2.push(x);
    while (!q1.empty()){
        int f = q1.front();
        q1.pop();
        q2.push(f);
    }
    while (!q2.empty()){
        int f = q2.front();
        q2.pop();
        q1.push(f);
    }
}
/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
    if (q1.empty() && q2.empty()){
        return -1;
    }   
    int f = q1.front();
    q1.pop();
    return f;
}
