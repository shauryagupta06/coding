//Check if paranthesis of a string composed of []/{}/()
//is balanced or not
//Using stack, O(n) time and O(n) space
#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main()
 {
	int t; cin >> t;
	while (t -- ){
	    string s;
	    cin >> s;
	    stack<char> stac;
	    int flag = 0;
	    for (int i = 0; i < s.size(); i++){
	        if (s[i] == '{' || s[i] == '(' || s[i] == '['){
	            stac.push(s[i]);
	        }
	        else {
	            if (stac.empty()){
	                flag = 1;
	                break;
	            }
	            char t = stac.top();
	            stac.pop();
	            if (s[i] == '}'){
	                if (t != '{'){
	                    flag = 1;
	                    break;
	                }
	            }
	            else if (s[i] == ')'){
	                if (t != '('){
	                    flag = 1;
	                    break;
	                }
	            }
	            else if (s[i] == ']'){
	                if (t != '['){
	                    flag = 1;
	                    break;
	                }
	            }
	            
	        }
	    }
	    if (!flag && stac.empty())
	        cout<<"balanced"<<endl;
	    else
	        cout<<"not balanced"<<endl;
	}
	return 0;
}