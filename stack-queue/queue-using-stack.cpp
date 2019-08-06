class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; 
/* The method push to push element into the queue */
void StackQueue :: push(int x)
 {
    s1.push(x);
    return;
 }
/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
    if (s1.empty() && s2.empty()){
        return -1;
    }
    if (!s2.empty()){
        int t =  s2.top();
        s2.pop();
        return t;
    }
    while (!s1.empty()){
        int t = s1.top();
        s1.pop();
        s2.push(t);
    }
    int t = s2.top();
    s2.pop();
    return t;
}

