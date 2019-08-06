/*A child is running up a staircase with n steps and can
 hop either 1 step, 2 steps or 3 steps at a time. Implement
a method to count how many possible ways the child can run 
up to the stairs. You need to return all possible number of 
ways.
Time complexity O(n). */
long staircase(int n){
long *ans = new long[n+1];

  ans[0]=1;
  ans[1]=1;
  ans[2]=2;
    
  for (int i=3;i<=n;i++){
    ans[i] = ans[i-1]+ans[i-2]+ans[i-3];
  }
  return ans[n];
    
}
