#include <iostream>
using namespace std;
void reverse(string& s,int begin,int end){
    char temp;
    while (begin < end){
        temp = s[begin];
        s[begin++] = s[end];
        s[end--] = temp;
    }
}
void reverseWords(string& s){
    int wordl = 0;
    char d = '.';
    int dot = (int)d;
    for (int i=0;i<=s.size();i++){
        
        if (s[i]== '.'){
            reverse(s,i-wordl,i-1);
            wordl=0;
        }
        else if(s[i] == '\0'){
            reverse(s,i-wordl,i-1);
        }
        else {
            wordl++;
        }
    }
    reverse(s,0,s.size()-1);
}
int main() {
	int t;cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    //reverse(s,0,s.size()-1);
	    reverseWords(s);
	    cout<<s<<endl;
	}
	return 0;
}