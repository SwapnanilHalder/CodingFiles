#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <utility>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cassert>
#include <chrono>
#include <numeric>
#define SPEED ios_base::sync_with_stdio(false)
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector<double>
#define vi2d vector<vector<double>> 
#define li list<int>
#define mii map<int, int>
#define msi map<string, int>
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.1415926535897932384626
#define MOD 1000000007
#define INF 9223372036854775800 
#define ll long long
#define int long long int
#define END cout<<"\n"
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define inpt(x) int x{0}; cin >> x
#define pl(x) cout << x << endl
#define all(v) v.begin(),v.end()
#define loop(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pmint(v) cout<< #v<<endl;loop(itr, v){cout << "\t" << itr->first << " ->  " << itr->second;END;}
#define pmpair(v) cout<< #v<<endl; cout << "	(" << v.first << " , " << v.second << ")";END
#define timestart auto start = chrono::high_resolution_clock::now()
#define timestop auto stop = chrono::high_resolution_clock::now();auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);cout << "Time taken by function: "<< duration.count() << " microseconds" << endl
using namespace std;
int gcd(int a, int b){return b ? gcd(b, a%b): a;}
int lcm(int a, int b){return (a*b)/gcd(a,b);}
template <class T> T Max(T x,T y){return (x>y)?x:y;}
template <class T> T Min(T x,T y){return (y>x)?x:y;}

vi input1l(){
	vi input(0);
	string str, num;
	getline(cin, str);
	stringstream X(str);
	while(getline(X, num, ' ')) {
		input.pb(stoll(num));
	}
	//pv(input);
	return input;
}

int m,n,minMax,maxMin,totall,k=0;
vi2d a(20, vi(20, 0));
vi row_minimum(20, 0);
vi col_max(20, 0);
double v;
int tabNo = 1;
vector<int> b;
vector<double> x,y;

void print();

void printTable();

void calc_Zj(){
	for(int j=0;j<=totall;j++){
		a[m+1][j] = 0;
		for (int i=0;i<m;i++){
			a[m+1][j] += (a[m][b[i]]*a[i][j]);
		}
	}
}

void calc_Zj_Cj(){
	for(int j=0;j<totall;j++){
		a[m+2][j] = a[m+1][j] - a[m][j];
	}
}

void changeTable(int c, int r){

	double div = a[r][c];
	if(div == 0)
		return;
	for(int i=0;i<=totall;i++){
		a[r][i] /= div;
	}
	for(int i=0;i<m;i++){
		double mult = a[i][c];
		if(i!=r)
			for(int j=0;j<=totall;j++){
				a[i][j] = a[i][j] - (mult*a[r][j]);
			}
	}
}

int min_Zj_Cj(){
	int index=0;
	for(int i=0;i<totall;i++)
		if(a[m+2][i]<a[m+2][index] && a[m+2][i]<0)
			index = i;
	if(index==0 && a[m+2][0]<0)
		return 1;
	else if(index>0)
		return index+1;
	else 
		return 0;
}

int minRat(int col){
	int index=0;
	for(int i=0;i<m;i++){
		if(a[index][col] <= 0)
			index++;
		if(a[i][totall]/a[i][col] < a[index][totall]/a[index][col] && a[i][col]>0)
			index = i;
	}
	return index+1;
}

int checkSaddlePoint(){
	
	for(int i=0;i<m;i++){
		double index = a[i][0];
		for(int j=0;j<n;j++)
			if(a[i][j]<index)
				index = a[i][j];
		row_minimum[i] = index;
	}
	for(int i=0;i<n;i++){
		double index = a[0][i];
		for(int j=0;j<m;j++)
			if(a[j][i]>index)
				index = a[j][i];
		col_max[i] = index;
	}
	print();
	double index = row_minimum[0];
	for(int i=0;i<m;i++)
		if(row_minimum[i]>index)
			index = row_minimum[i];
	maxMin = index;
	index = col_max[0];
	for(int i=0;i<n;i++)
		if(col_max[i]<index)
			index = col_max[i];
	minMax = index;

	if(minMax==maxMin){
		for(int i=0;i<n;i++)
			y.pb(0);
		for(int i=0;i<m;i++)
			x.pb(0);
		cout << "\nGiven Problem has a Saddle Point at (";
		for (int i=0;i<m;i++)
			if(row_minimum[i]==minMax){
				cout << i+1 << ",";
				x[i] = 1;
				break;
			}
		for(int i=0;i<n;i++)
			if(col_max[i]==minMax){
				cout << i+1 << ")";
				y[i] = 1;
				break;
			}
		cout << endl;	
	for(int i=0;i<n;i++)
		cout << "y" << i+1 << " = " << y[i] << endl;
	cout << endl;
	for(int i=0;i<m;i++)
		cout << "x" << i+1 << " = " << x[i] << endl;
	cout << "\nAn Optimal strategy for Player A = (";
	for(int i=0;i<m-1;i++)
		cout << x[i] << ",";
	cout << x[m-1] << ")" << endl;
	cout << "\nAn Optimal strategy for Player B = (";
	for(int i=0;i<n-1;i++)
		cout << y[i] << ",";
	cout << y[n-1] << ")" << endl;
	cout << "\nValue of Game = " << minMax << endl;
		return 1;
	}

	return 0;
}

void performSimplex(){
	int row;
	int col = min_Zj_Cj();
	while(col!=0){
		row = minRat(col-1);
		changeTable(col-1,row-1);
		b[row-1] = col-1;
		calc_Zj();
		calc_Zj_Cj();
		printTable();
		col = min_Zj_Cj();
	}
}

void gameTheory(){
	int stable = checkSaddlePoint();
	if(stable==1)
		return;
	else
		cout << "\nGame is Unstable using simplex to solve further." << endl;
	if(min(maxMin,minMax)<0){
		double index = row_minimum[0]; 
		for(int i=0;i<m;i++){
			if(index>row_minimum[i])
				index = row_minimum[i];	
		}
		k = -index;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				a[i][j] = a[i][j] + k;
	}
	totall = n+m;
	for(int i=0;i<m;i++){
		a[i][n+i] = 1;
		b.pb(n+i);
		a[i][totall] = 1;
	}
	for(int i=0;i<n;i++){
		a[m][i] = 1;
	}
	calc_Zj();
	calc_Zj_Cj();
	printTable();
	performSimplex();

	v = 1/a[m+1][totall];
	cout << endl;
	for(int i=0;i<n;i++){
		int flag = 0;
		int j;
		for(j=0;j<m;j++)
			if(b[j]==i){
				flag = 1;
				break;
			}		
		if(flag==1)
			y.pb(a[j][totall]*v);
		else
			y.pb(0);
	}
	for(int i=0;i<m;i++)
		x.pb(a[m+1][n+i]*v);
	cout << endl;	
	for(int i=0;i<n;i++)
		cout << "y" << i+1 << " = " << y[i] << endl;
	cout << endl;
	for(int i=0;i<m;i++)
		cout << "x" << i+1 << " = " << x[i] << endl;
	cout << "\nSa = (";
	for(int i=0;i<m-1;i++)
		cout << x[i] << ",";
	cout << x[m-1] << ")" << endl;
	cout << "\nSb = (";
	for(int i=0;i<n-1;i++)
		cout << y[i] << ",";
	cout << y[n-1] << ")" << endl;
	cout << "\nValue of Game = " << v-k << endl;
}

int32_t main(){
	cout << "Enter No. of Strategies for Player A : ";
	cin >> m;
	cout << "Enter No. of Strategies for Player B : ";
	cin >> n;

	vi2d tab(m, vi(n, 0));
	cout << "Enter the PayOffs row-wise: \n";
	For(i, 0, m) {
		For(j, 0, n) {
			cin >> tab[i][j];
		}
	}

	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			a[i][j] = tab[i][j];
	gameTheory();
}

void print() {
	for(int j=0;j<n;j++)
		cout << "\tB" << j+1;
	cout << "\t| RowMin";
	cout << endl;
	for(int i=0;i<m;i++){
		cout << "A" << i+1 << "\t";
		for(int j=0;j<n;j++)
			cout << a[i][j] << "\t";
		cout << "| " << row_minimum[i];
		cout << endl;
	}
	for(int i=0;i<n+1;i++)
		cout << "--------";
	cout << "\nColMax\t";
	for(int i=0;i<n;i++)
		cout << col_max[i] << "\t";
	cout << endl;
}

void printTable(){
	cout << "\n\t\t\tTable " << tabNo << endl;
	//print Cj
	cout << "\tCj\t";
	for(int j=0;j<totall;j++){
		printf ("%.2f\t", a[m][j]);
	}
	//print Heading
	cout << endl;
	cout << "Cb\tbasis\t";
	for(int j=0;j<totall;j++){
		cout << "y" << j+1 << "\t";
	}
	cout << "yb\n";
	for(int i=0;i<totall+3;i++)
		cout << "========";
	cout << endl;
	//print elements
	for(int i=0;i<m;i++){
		cout << a[m][b[i]] << "\t" << "y" << b[i]+1 <<"\t";
		for(int j=0;j<=totall;j++){
			printf ("%.2f\t", a[i][j]);
		}
		cout << endl;
	}

	//print Zj and Zj-cj
	for(int i=0;i<totall+3;i++)
		cout << "========";
	cout << endl;
	cout << "\tZj\t";
	for(int i=0;i<=totall;i++){
		printf ("%.2f\t", a[m+1][i]);
	}
	cout << endl;
	cout << "\tZj-Cj\t";
	for(int i=0;i<totall;i++){
		printf ("%.2f\t", a[m+2][i]);
	}
	cout << endl;

	tabNo++;
}