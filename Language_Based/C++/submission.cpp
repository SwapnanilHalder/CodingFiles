#include<iostream>

#define For(i,a,b) for(int i=a;i<b;i++)
#define loop(i,j) For(i,0,3)For(j,0,3)
#define END cout << "\n"
using namespace std;

void put_input(int arr[][3], int t, int x);
void user_input(int arr[][3], int t);

void print_board(int arr[][3]) {
    For(i, 0, 3) {
        cout << " -------------"<<endl;
        cout << " | ";
        For(j, 0, 3) {
            if(arr[i][j] == -1) cout << "_";
            if(arr[i][j] == 10) cout << "O";
            if(arr[i][j] == 100) cout << "X";
            cout << " | ";
        }END;
    }
    cout << " -------------"<<endl;
}

void cpu_plays(int arr[][3], int t) {
    int sum{0};
    loop(i,j) sum+=arr[i][j];
    if(sum == -9) {
        put_input(arr, 3-t, 3);
    }
    else if(sum == 2) {
        
    }
    print_board(arr);
}

void put_input(int arr[][3], int t, int x) {
    x--; int inp;
    if(t == 1)inp = 100;
    if(t == 2) inp = 10;
    arr[x/3][x%3] = inp;
}

void user_input(int arr[][3], int t) {
    int x; 
    cout << "Give input (1-9) : ";
    cin >> x;
    put_input(arr, t, x);
}

void game_start(int arr[][3], int t) {
    if(t == 1) {
        user_input(arr, t);
        cpu_plays(arr, t);
        cout << "After input : \n";print_board(arr);
    }
    else if(t == 2) {
        cpu_plays(arr, t);
        user_input(arr, t);
        cout << "After input : \n";print_board(arr);
    }
}

int main() {
    int arr[3][3];
    For(i, 0, 3) {
        For(j, 0, 3) {
            arr[i][j] = -1;
        }
    }
    print_board(arr);
    int t{0};
    while(!(t == 1 || t== 2)) {
        cout << "What player would you like to be (Player 1 : X) or, Player 2 : O) [Player 1 plays first]? : ";
        cin >> t;
    }
    game_start(arr, t);
}