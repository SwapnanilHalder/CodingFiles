#include <bits/stdc++.h>
#define For(i, a, b) for(int i=a; i<b; i++)
using namespace std;


int SolveTejasProblem(int num)
{
	string number = to_string(num);
	string store = number;

	For(i, 0, number.size()) {
		For(j, i+1, number.size()) {
			swap(number[i], number[j]);
			if (stoi(store) < stoi(number) ) {
				store = number;
            }
			swap(number[i], number[j]);
		}
	}
	return stoi(store);
}

int main()
{
	int num = 432;
	cout << SolveTejasProblem(num) << endl;
	num = 2736;
	cout << SolveTejasProblem(num) << endl;
	num = 4596;
	cout << SolveTejasProblem(num) << endl;
	return 0;
}
