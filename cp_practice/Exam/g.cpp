#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {

		if(D.size() < 1 || N <= 0)
			return 0;
		string num =to_string(N);
		int dig = num.size();
		int res = 0;
		for(int i =  1; i < dig; i++)
			res += pow(D.size(), i);
		int a = 0;
		for(int i =0; i <dig; i++)
		{
			a = 0;
			for(int j = 0; j < D.size(); j++)
			{
				if(D[j][0] < num[i])
					res += pow(D.size(), dig-(i+1));
				else if(D[j][0] == num[i])
				{
					a = 1;
					break;
				}
			}
			if(!a)
				break;
		}
		return res+a;
	}
    
};


int main() {
    Solution mySolution;
    vector<int> arr{4,2,3,0,3,1,2};
    int start = 5;
    string str = "abcdefg";
    cout << "Answer : " << endl;
    cout << mySolution.answer() << endl;
}	
    
    
