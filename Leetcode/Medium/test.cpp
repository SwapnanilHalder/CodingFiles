// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t=1;
    while(t--)
    {
        string s="geeksforgeeks";
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}// } Driver Code Ends


string firstRepChar(string s)
{
    //code here.
    set<char> sett;
    for(int i=0; i<s.size(); i++) {
        cout << "1\n";
        if(sett.find(s[i]) != sett.end()) {
            string a;
            a+= s[i];
            return a;
        }
        sett.insert(s[i]);
    }
    return("-1");
}