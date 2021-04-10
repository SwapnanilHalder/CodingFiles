#include <iostream>
#include <cmath>
using namespace std;

int d[10]={0};
int dmap[10]={-1};
float mat[10][10], b[10], temp[10][10], constants[10];
float ans[10][10], z[10];
int R, C;

int duald[10]={0};
int dualdmap[10]={-1};
float dualmat[10][10], dualb[10], dualtemp[10][10], dualconstants[10];
float dualans[10][10], dualz[10];
int dualR, dualC;

int main()
{
	int in_var, eqn, var;
	int flag = 0;int incos=0;
	string inequality;
	cout << "Enter no. of variables\n";
	cin >> in_var;
	var= in_var;
	cout << "Enter no. of equations\n";
	cin >> eqn;
	cout << "Now enter all the inequalities in <= format : \n";
	for(int i = 0 ; i < eqn ; i++)
	{
		cout << "Enter coefficients and constant term of equation no " << i+1 << " seperated by spaces:\n";
		for(int j = 0 ; j <= in_var ; j++)
		{
			cin >> mat[i][j];
		}

	}
	
	for(int i=0;i < eqn;i++)
	{
		for(int j=0;j<=in_var;j++)
		{
			temp[i][j] = mat[i][j];
		}
	}
	
	cout << "Enter the objective function to be maximised along with constant term (If the problem is minimization, multiply the function by -1) :\n";
	for(int i=0;i<=in_var;i++)
	{
		int a=0;
		cin >> a;
		if(a>0)flag=1;
        if(a < 0) {
            cout << "Minimum : 0\n";
        }
		temp[eqn][i] = -a;
	}
	
	cout << "\nInitial simplex table\n ";
	for(int i=0;i <= eqn;i++)
	{
		for(int j=0;j<=in_var;j++)
		{
			cout << " " << temp[i][j];
		}
		cout << endl;
	}
	int dummy=1;
	cout << "\n Flag is " << flag;
	while(flag) {
		
		float min = 10000; int prod=0;
		int Min_Pos = -1;
		for(int i=0;i<in_var;i++)
		{
			if(temp[eqn][i] < 0)prod=1;
		}
		if(!prod){
			cout << "Prod is " << prod;
			flag=0;
			break;
		}
				
		for(int i=0;i<in_var;i++)
		{
			if(temp[eqn][i] <= min)
			{
				min = temp[eqn][i];
				Min_Pos = i;
			}
		}
		
		cout << "\n Value of Min_Pos is " << Min_Pos << "  and incoming variable is  " << in_var << endl;
		int pivot = -1;
		float minp = 10000;
		for(int i=0;i< eqn;i++)
		{
			if(1.0*temp[i][in_var]/temp[i][Min_Pos] < minp && 1.0*temp[i][in_var]/temp[i][Min_Pos]>0)
			{
				minp = 1.0*temp[i][in_var]/temp[i][Min_Pos];
				pivot = i;
			}
		}
		
		if(pivot==-1){
			flag=0;
			incos = 1;
			break;
		}
		cout << "\n Pivot : " << temp[pivot][Min_Pos] << " at pos " << pivot;
		cout << "\n Most negative element " << min;
		
		d[Min_Pos] = 1;
		dmap[Min_Pos] = pivot;
		float p = temp[pivot][Min_Pos];
		
		for(int i=0;i<=eqn;i++)
		{
			for(int j=0;j<=in_var;j++)
			{
				if(i==pivot || j==Min_Pos)continue;
				temp[i][j] = temp[i][j] - 1.0*temp[pivot][j]*temp[i][Min_Pos]/p;
			}
		}

		for(int i=0;i<=eqn; i++)
		{
			if(i==pivot)continue;
			temp[i][Min_Pos] = -temp[i][Min_Pos]/p;
		}
		for(int j=0;j<=in_var;j++)
		{
			if(j==Min_Pos)continue;
			temp[pivot][j] = temp[pivot][j]/p;
		}
		temp[pivot][Min_Pos] = 1.0/temp[pivot][Min_Pos];

		
		
		cout << "\n Simplex table\n ";
		for(int i=0;i <= eqn;i++)
		{
			for(int j=0;j<=in_var;j++)
			{
				cout <<temp[i][j] << " ";
			}
			cout << endl;
		}
	}

	if(incos)
	{
		cout << "\n\n The given system of equations inconsistent  ";
		return 0;
	}

	for(int j=0;j<in_var;j++)
	{
		if(temp[eqn][j]==0)
		{
			cout << "\n\n However infinite solutions exist for this case ";
			break;
		}
	}
	
	bool flagdual = true;
    float x_b_max;
	while(flagdual){

		bool ifc=true;
		for(int i=0;i < eqn;i++)
		{
			if(fabs(floor(temp[i][in_var])-temp[i][in_var])>1e-5){
				ifc = false;break;
			}
		}
		if(ifc){flagdual=false;break;}
		x_b_max=-1; int xbpos;
		for(int i=0;i < eqn;i++)
		{
			for(int j=0;j<=in_var;j++)
			{
				dualtemp[i][j] = temp[i][j];
				if(j==in_var && fabs(floor(temp[i][j])-temp[i][j])>1e-5){
					if((temp[i][j]-floor(temp[i][j])) > x_b_max){
						x_b_max = temp[i][j]-floor(temp[i][j]);
						xbpos = i;
					}
				}
			}
		}
		cout << "\nvalue of x_b_max: " << x_b_max << endl;
		if((int)x_b_max==-1 || fabs(x_b_max-1)<1e-5){cout << "\n"<<endl;return 0;}
		cout << "\n value of xbpos : " << xbpos;
		for(int j=0;j<=in_var;j++){
			dualtemp[eqn][j] = floor(temp[xbpos][j]) - temp[xbpos][j];
			dualtemp[eqn+1][j] = temp[eqn][j];
		}
		eqn = eqn +1;

		cout << "\nPrinting in-between table: \n";
		for(int i=0;i <= eqn;i++)
		{
			for(int j=0;j<=in_var;j++)
			{
				cout << dualtemp[i][j] << " " ;
			}
			cout << endl;
		}
	
		float min = 10000;int Min_Pos = -1;
			int pivot = -1;
		
			for(int i=0;i< eqn;i++)
			{
				if(dualtemp[i][in_var] < min){
					min = dualtemp[i][in_var];
					pivot = i;
				}
			}

		cout << "\n Value of pivot: " << pivot << endl;
			float minp = 10000;
		for(int j=0;j<in_var;j++){
			float f = 1.0*dualtemp[eqn][j]/dualtemp[pivot][j];
			cout << "\n Value f : " << fabs(f) << " ";
			if(fabs(f) < minp){minp = fabs(f);Min_Pos = j;cout << " \n MIn_Posi selected as: " << j << endl;}
		}
		float p = dualtemp[pivot][Min_Pos];
		cout << "\n Value of Min_Pos and p: " << Min_Pos << " " << p << endl;
		for(int i=0;i<=eqn;i++)
			{
				for(int j=0;j<=in_var;j++)
				{
					if(i==pivot || j==Min_Pos)continue;
					dualtemp[i][j] = dualtemp[i][j] - 1.0*dualtemp[pivot][j]*dualtemp[i][Min_Pos]/p;
				}
			}

		for(int i=0;i<=eqn; i++)
			{
				if(i==pivot)continue;
				dualtemp[i][Min_Pos] = -dualtemp[i][Min_Pos]/p;
			}
			for(int j=0;j<=in_var;j++)
			{
				if(j==Min_Pos)continue;
				dualtemp[pivot][j] = dualtemp[pivot][j]/p;
			}
			dualtemp[pivot][Min_Pos] = 1.0/dualtemp[pivot][Min_Pos];

		for(int i=0;i <= eqn;i++)
			{
				for(int j=0;j<=in_var;j++)
				{
					cout <<dualtemp[i][j] << " ";
					temp[i][j] = dualtemp[i][j];
				}
				cout << endl;
			}
	}
    cout << " FInal max value : " << ceil(x_b_max) << endl;
	return 0;
}
