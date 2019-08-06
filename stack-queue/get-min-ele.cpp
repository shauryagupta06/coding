//Design a stack which always stores minimum elemnet
//in its member minEle and performs operations, push,
//pop and additional getMin all in O(1) space and
//O(1) time

//The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};

/*returns min element from stack*/
int _stack :: getMin()
{
   if (s.empty()){
       return -1 ;
   }
   return minEle;
}
/*returns poped element from stack*/
int _stack ::pop()
{
   if (s.empty()){
       return -1 ;
   }
   int t = s.top();
   s.pop();
   int ans;
   if (t < minEle){
       ans = minEle;
       minEle = 2*minEle - t;
   }
   else{
       return t;
   }
   return ans;
}
/*push element x into the stack*/
void _stack::push(int x)
{
   if (s.empty()){
       s.push(x);
       minEle = x;
       return;
   }
   if (x < minEle){
       s.push(2*x - minEle);
       minEle = x;
   }
   else{
       s.push(x);
   }
}
