#include<iostream>

#define For(i,a,b) for(int i=a;i<b;i++)
#define loop(i) For(i,1,10)
#define END cout << "\n"
using namespace std;

int arr[10];
int t = 0;

void put_input(int t, int x);
void user_input();
void cpu_plays();
void game_runs();

void print_board() {
    For(i, 1, 10) cout<< arr[i] << " ";END;
    For(i, 0, 3) {
        cout << " -------------"<<endl;
        cout << " | ";
        For(j, 0, 3) {
            if(arr[i*3 + j +1] == -1) cout << "_";
            if(arr[i*3 + j +1] == 10) cout << "O";
            if(arr[i*3 + j +1] == 100) cout << "X";
            cout << " | ";
        }END;
    }
    cout << " -------------"<<endl;
}

bool check_win() {
    For(i, 0, 3) {
        if( (arr[1+i] == arr[4+i] == arr[7+i]) && (arr[1+i] != -1) ) return 1;
    }
    For(i, 0, 3) {
        if( (arr[1+i*3] == arr[2+i*3] == arr[3+i*3]) && (arr[1+i*3] != -1) ) return 1;
    }
    if( (arr[1] == arr[5] == arr[9]) && (arr[1] != -1) ) return 1;
    if( (arr[3] == arr[5] == arr[7]) && (arr[3] != -1) ) return 1;
    return 0;
}

void cpu_plays() {
    int sum{0};
    loop(i) sum+=arr[i];
    if(sum == 540) {
        cout << "The match has come to a draw\n";
        return;
    }
    if(sum == -9) {
        arr[1] = 100;
    }
    else if(sum == 92) {
        if(arr[2] == 100 || arr[4] == 100) arr[1] = 10;
        if(arr[6] == 100 || arr[8] == 100) arr[9] = 10;
        if(arr[5] == 100) arr[1] = 10;
        else arr[5] = 10;
    }
    else if(sum == 103) {
        if(arr[5] == 10) arr[9] = 100;
        else if(arr[9] == 10) arr[3] = 100;
        else arr[5] = 100;
    }
    else if(sum == 204) {
        
    }

    cout << "SUM = " << sum<<endl;
    print_board();
    if(check_win()) {
        cout << "Player " << 3-t << " has won the game\n";
        return;
    }
    return game_runs();
}

void put_input(int t, int x) {
    int inp;
    if(t == 1) {
        inp = 100; 
    }
    if(t == 2) inp = 10;
    arr[x] = inp;
}

void user_input() {
    int x; 
    cout << "Give input (1-9) : ";
    cin >> x;
    put_input(t, x);
}

void game_start() {
    if(t == 1) {
        user_input();
        cpu_plays();
        cout << "After input : \n";print_board();
    }
    else if(t == 2) {
        cpu_plays();
        cout << "After input : \n";print_board();
    }
}

void game_runs() {
    int sum{0};
    loop(i) sum+=arr[i];
    if(sum == 450) {
        cout << "The match has come to a draw\n";
        return;
    }
    user_input();
    cpu_plays();
    cout << "After input : \n";print_board();
}

int main() {
    arr[0] = 0;
    For(i, 1, 10) arr[i] = -1;
    print_board();
    while(!(t == 1 || t== 2)) {
        cout << "What player would you like to be (Player 1 : X) or, Player 2 : O) [Player 1 plays first]? : ";
        cin >> t;
    }
    game_start();
}