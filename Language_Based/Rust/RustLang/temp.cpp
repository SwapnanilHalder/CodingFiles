#include<iostream>  
#include <vector>
#include <map>
#include <string>
using namespace std;  
   
int main()  
{  
  int n, m1, m2, m3, m4;
  cin >> n >> m1 >> m2 >> m3 >> m4;
  map<char, vector<string> > mp;

  for (int i = 0; i < n; i++)
  {
    string s;
    int d;
    cin >> s >> d;

    if(m1 <= d && d < m2){
      mp['S'].push_back(s);
    }
    else if(m2 <= d && d < m3){
      mp['M'].push_back(s);
    }
    else if(m3 <= d && d < m4){
      mp['L'].push_back(s);
    }
    else{
      mp['X'].push_back(s);
    }
  }

  vector<char> ans = {'S', 'M', 'L', 'X'};
  for(auto i:ans){
    cout << i << ":\n";
    for(auto j:mp[i]){
      cout << j << "\n";
    }
  }
  return 0;  
}  