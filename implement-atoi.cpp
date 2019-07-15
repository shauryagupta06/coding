//string to integer
//"123" = 123
//-1 if any char other than digit present, eg. 12a
#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int getNumber(string str){
    int number = 0;
    for (int i = 0; i< str.size(); i++){
        if (str[i]<48 || str[i]>57)
            return -1;
        number += (pow(10,(str.size()-1)-i)*(str[i]-48));
    }
    return number;
}
int atoi(string str)
{   
    int ans;
    if (str[0] == '-')
        ans = -1*getNumber(str.substr(1,str.size()-1));
    else
        ans = getNumber(str);
    return ans;
}