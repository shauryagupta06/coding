void computeLPS(string pat, int M,int *lps ){
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i<M){
        if (pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if (len != 0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}
int strstr(string s, string x)
{
    int M = x.size();
    int N = s.size();
    
    int lps[M];
    
    computeLPS(x,M,lps);
    
    int i=0;
    int j=0;
    
    while (i < N){
        if (s[i] == x[j]){
            i++;
            j++;
        }
        if (j==M){
            cout<<"pattern found at "<<i-j<<endl;
            j = lps[j-1];
        }
        else if (i<N && s[i] != x[j]){
            if (j != 0)
                 j = lps[j-1];
            else
                i = i + 1;
        }
            
    }
    
    return -1;
}