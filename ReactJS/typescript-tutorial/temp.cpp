#include <bits/stdc++.h>
using namespace std;
 
string D_to_B(long num)
{
    string str;
      while(num){
      if(num & 1)
        str+='1';
      else 
        str+='0';
      num>>=1;
    }   
    reverse(str.begin(), str.end());
    return str;
}
 
void reverse(string str)
{
  for(int i=str.size()-1 ; i>=0 ; i--)
   cout<< str[i];
}