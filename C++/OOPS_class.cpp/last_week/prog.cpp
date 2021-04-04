#include<iostream>
using namespace std;
#define MAX 11


int V,E;
int adj_Matrix[MAX][MAX];
int outPut[MAX][MAX];
int output_vertex[MAX];
int outPutV[MAX];

void zero_Matrix(int arr[], int n){
	for(int i=0;i<n; i++)
		arr[i] = 0;
}

int isClique(int stored[]){
	for(int i=0;i<V;i++){
		if(stored[i]){
			for(int j=0;j<V; j++){
				if(i==j)continue;
				if(stored[j]){
					if(adj_Matrix[i][j]==0)
						return 0;
				}
			}
		}
	}
	return 1;
}

int is_Covered(int stored[]){
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			if(adj_Matrix[i][j])
				if(stored[i]==0 and stored[j]==0)
					return 0;
	return 1;
}

void answer (int V, int E, int Arr[][2]) {

    for(int i = 0; i< MAX; i++) zero_Matrix(adj_Matrix[i], MAX);
    for(int i=0;i<E;i++){
		int u,v;
		u = Arr[i][0];
		v = Arr[i][1];
		adj_Matrix[u][v]=adj_Matrix[v][u]=1;
	}

	int stored[MAX];
	int ans = 0, cnt;
	for(int i=1;i<(1LL<<V);i++){
		cnt = 0;
		zero_Matrix(stored,V);

		for(int j=0; j<V; j++){
			if((1LL<<j)&(i)){
				cnt++;
				stored[j]=1;
			}
		}
		if(isClique(stored) and ans<cnt){
			ans = cnt;
			for(int i=0;i<V;i++)
				output_vertex[i] = stored[i];

			for(int i=0;i<V;i++)
				for(int j=i+1;j<V;j++)
					outPut[j][i] = outPut[i][j] = (stored[i]*stored[j])?1:0;
		}
	}
    cout << "For the graph : \n";
    for(int i {0}; i<V; i++) {
        cout << " { " << Arr[i][0] << ", " << Arr[i][1] << "} ; ";
    }    cout << "\n";
	cout<<"max Clique Size = "<<ans<<"\n";
	cout<<"Maximum Clique :";for(int i=0;i<V;i++)if(output_vertex[i])cout<<i<<" ";cout<<"\n";
    cout << "\n";

	ans = V;
	for(int i=1;i<(1LL<<V);i++){
		cnt = 0;
		zero_Matrix(stored,V);
		for(int j=0; j<V; j++){
			if((1LL<<j)&(i)){
				cnt++;
				stored[j]=1;
			}
		}
		if(is_Covered(stored) and ans>cnt){
			ans = cnt;
			for(int i1=0;i1<V;i1++)
				outPutV[i1] = stored[i1];
		}
	}
	cout<<"min vertex cover size = "<<ans<<"\n";
	cout<<"Min vertex cover :\n";
	for(int i=0;i<V;i++)
	{
		if(outPutV[i])
			cout<<i<<" ";
	}
	cout<<endl<<endl;
}

int main(){

	//input
	V = 6; // Actually V = 6; vertex will be 1,2,...V , so we are increasing V to  V+1, to compensate for the 0th position
	E = 10;
	int Arr[][2] = { {0,1}, {0,2}, {0,5}, {1,2}, {1,3}, {1,4}, {1,5}, {2,3}, {2,5}, {3,4}  }; ;

    answer(V, E, Arr);
    V = 7;
    E = 7;
    int Arr1[][2] = {{0,3}, {0,1}, {1,2},{1,4}, {2,5}, {2,6}, {4,5}};
    answer(V,E, Arr1);
	
	return 0;
}
