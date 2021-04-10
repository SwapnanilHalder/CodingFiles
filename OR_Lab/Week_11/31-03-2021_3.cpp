#include <bits/stdc++.h>
using namespace std;

int m,n,minMax,maxMin,tot,k=0;
double a[20][20] = {0};
double rowMin[20],colMax[20],v;
int tabNo = 1;
vector<int> b;
vector<double> x,y;

void print(){
	for(int j=0;j<n;j++)
		cout << "\tB" << j+1;
	cout << "\t| RowMin";
	cout << endl;
	for(int i=0;i<m;i++){
		cout << "A" << i+1 << "\t";
		for(int j=0;j<n;j++)
			cout << a[i][j] << "\t";
		cout << "| " << rowMin[i];
		cout << endl;
	}
	for(int i=0;i<n+1;i++)
		cout << "--------";
	cout << "\nColMax\t";
	for(int i=0;i<n;i++)
		cout << colMax[i] << "\t";
	cout << endl;
}

void printTable(){
	cout << "\n\t\t\tTable " << tabNo << endl;
	//print Cj
	cout << "\tCj\t";
	for(int j=0;j<tot;j++){
		printf ("%.2f\t", a[m][j]);
	}
	//print Heading
	cout << endl;
	cout << "Cb\tbasis\t";
	for(int j=0;j<tot;j++){
		cout << "y" << j+1 << "\t";
	}
	cout << "yb\n";
	for(int i=0;i<tot+3;i++)
		cout << "========";
	cout << endl;
	//print elements
	for(int i=0;i<m;i++){
		cout << a[m][b[i]] << "\t" << "y" << b[i]+1 <<"\t";
		for(int j=0;j<=tot;j++){
			printf ("%.2f\t", a[i][j]);
		}
		cout << endl;
	}

	//print Zj and Zj-cj
	for(int i=0;i<tot+3;i++)
		cout << "========";
	cout << endl;
	cout << "\tZj\t";
	for(int i=0;i<=tot;i++){
		printf ("%.2f\t", a[m+1][i]);
	}
	cout << endl;
	cout << "\tZj-Cj\t";
	for(int i=0;i<tot;i++){
		printf ("%.2f\t", a[m+2][i]);
	}
	cout << endl;

	tabNo++;
}

void calcZj(){
	for(int j=0;j<=tot;j++){
		a[m+1][j] = 0;
		for (int i=0;i<m;i++){
			a[m+1][j] += (a[m][b[i]]*a[i][j]);
		}
	}
}

void calcZjCj(){
	for(int j=0;j<tot;j++){
		a[m+2][j] = a[m+1][j] - a[m][j];
	}
}

void changeTable(int c, int r){

	double div = a[r][c];
	if(div == 0)
		return;
	for(int i=0;i<=tot;i++){
		a[r][i] /= div;
	}
	for(int i=0;i<m;i++){
		double mult = a[i][c];
		if(i!=r)
			for(int j=0;j<=tot;j++){
				a[i][j] = a[i][j] - (mult*a[r][j]);
			}
	}
}

int minZjCj(){
	int index=0;
	for(int i=0;i<tot;i++)
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
		if(a[i][tot]/a[i][col] < a[index][tot]/a[index][col] && a[i][col]>0)
			index = i;
	}
	return index+1;
}

int checkSaddlePt(){
	
	for(int i=0;i<m;i++){
		double index = a[i][0];
		for(int j=0;j<n;j++)
			if(a[i][j]<index)
				index = a[i][j];
		rowMin[i] = index;
	}
	for(int i=0;i<n;i++){
		double index = a[0][i];
		for(int j=0;j<m;j++)
			if(a[j][i]>index)
				index = a[j][i];
		colMax[i] = index;
	}
	print();
	double index = rowMin[0];
	for(int i=0;i<m;i++)
		if(rowMin[i]>index)
			index = rowMin[i];
	maxMin = index;
	index = colMax[0];
	for(int i=0;i<n;i++)
		if(colMax[i]<index)
			index = colMax[i];
	minMax = index;

	if(minMax==maxMin){
		for(int i=0;i<n;i++)
			y.push_back(0);
		for(int i=0;i<m;i++)
			x.push_back(0);
		cout << "\nGiven Problem has a Saddle Point at (";
		for (int i=0;i<m;i++)
			if(rowMin[i]==minMax){
				cout << i+1 << ",";
				x[i] = 1;
				break;
			}
		for(int i=0;i<n;i++)
			if(colMax[i]==minMax){
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
	cout << "\nSa = (";
	for(int i=0;i<m-1;i++)
		cout << x[i] << ",";
	cout << x[m-1] << ")" << endl;
	cout << "\nSb = (";
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
	int col = minZjCj();
	while(col!=0){
		row = minRat(col-1);
		changeTable(col-1,row-1);
		b[row-1] = col-1;
		calcZj();
		calcZjCj();
		printTable();
		col = minZjCj();
	}
}

void gameTheory(){
	int stable = checkSaddlePt();
	if(stable==1)
		return;
	else
		cout << "\nGame is Unstable using simplex to solve further." << endl;
	if(min(maxMin,minMax)<0){
		double index = rowMin[0]; 
		for(int i=0;i<m;i++){
			if(index>rowMin[i])
				index = rowMin[i];	
		}
		k = -index;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				a[i][j] = a[i][j] + k;
	}
	tot = n+m;
	for(int i=0;i<m;i++){
		a[i][n+i] = 1;
		b.push_back(n+i);
		a[i][tot] = 1;
	}
	for(int i=0;i<n;i++){
		a[m][i] = 1;
	}
	calcZj();
	calcZjCj();
	printTable();
	performSimplex();

	v = 1/a[m+1][tot];
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
			y.push_back(a[j][tot]*v);
		else
			y.push_back(0);
	}
	for(int i=0;i<m;i++)
		x.push_back(a[m+1][n+i]*v);
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

int main(){
	m = 2;
	n = 4;
	double tab[m][n] = {{4,0,6,-2},{2,6,1,7}};
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			a[i][j] = tab[i][j];
	gameTheory();
	
	return 1;
}