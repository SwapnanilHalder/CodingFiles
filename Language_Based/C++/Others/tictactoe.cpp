#include <iostream>
#define For(i,a,b) for(int i=a;i<b;i++)
#define loop(i) For(i,0,9)
#define END cout << "\n"
using namespace std;
#define blank 0  //if cell is not occupied//
#define first 1// id of first player//
#define second -1 // id of second player//
char characters[] = {'O', ' ', 'X'}; //global declare//
const int N = 3;
int board[N*N],player,opponent;

void assign_p(int fplayer) {
    if(fplayer==1)
    player=1,opponent=-1;
    else
    player=-1,opponent=1;
}
void fill_board() // Making all the cells filled up        
{
    For(i,0, N*N)      
        board[i] = blank;
}                                       

bool Draw(){
    For(i,0, N*N) 
        if (board[i] == blank)         // play untill a cell is empty//
            return false;

    return true;                 
}

// to check whether player has won or opponent has won, returns 0 if it is a draw//

int eval_id() {
   For(row, 0, 3) { 
        if (board[N*row]==board[N*row+1]&& 
            board[N*row+1]==board[N*row+2]) 
        { 
            if (board[N*row]==player) 
                return player; 
            else if (board[N*row]==opponent) 
                return opponent; 
        } 
    } 
  
    // column check//
    For(col, 0, 3) { 
        if (board[col]==board[col+3] && 
            board[col+3]==board[col+6]) { 
            if (board[col]==player) 
                return player; 
  
            else if (board[col]==opponent) 
                return opponent; 
        } 
    } 
  
    if (board[0]==board[4] && board[4]==board[8]) { 
        if (board[0]==player) 
            return player; 
        else if (board[0]==opponent) 
            return opponent; 
    } 
  
    if (board[2]==board[4]&&board[4]==board[6]) { 
        if (board[2]==player) 
            return player; 
        else if (board[2]==opponent) 
            return opponent; 
    } 
    // If None of them won : 
    return 0; 
}
// a function to check all possible moves and to find the best move in this case//
int finds(int id, int &optimum_move) {
   // if game is draw//
    if (Draw())
    return 0;

    int optimal_total = -2;

    // check all cell in the board//
    for (int i = 0; i < N * N; i++) {
        // if cell is empty//
        if (board[i] == blank) {
           // continue game and fill the cell// 
            board[i] = id;

            //check if the player with identity "id" win//
            if (eval_id()==id) {
                optimum_move = i;
    
                board[i] = blank; // reset move to blank//
                return 1;
            }

            else {
                int move_temporary; // to store best move//

                // if our opponent wins then it returns negative total//
                int total = -1 * finds(-id,move_temporary);  
                board[i] = blank; //reset cell to empty//

                if (total == 1) {
                    optimum_move = i;
                    return 1;
                }
                else if (total > optimal_total) {
                    optimal_total = total;
                    optimum_move = i;
                }
            }
        }
    }
    return optimal_total;
}

void print_matrix() {
    for (int row = 0; row< N; row++) {
        cout << " -------------"<<endl;
        cout << " | ";
        for (int col = 0; col < N; col++) {
            cout << characters[board[col+N*row] + 1] ;
            cout << " | ";
        } END;
    }
    cout << " -------------"<<endl;
}

int play() {
    int fplayer;
    cout<<"to move first : 1"<<endl;
    cout<<"to move second: -1"<<endl;
    cin >> fplayer;
    assign_p(fplayer);// assign you and CPU an identity//

    fill_board(); // intialise tic-tac-toe board //

    int turn = first; 
    bool end = false;  
    
    // to show the numbering of cells//
    cout<<"these are the cell numbers"<<endl;

    for (int row = 0; row< N; row++) {
        cout << " -------------"<<endl;
        cout << " | ";
        for (int col = 0; col < N; col++) {
            cout << N*row+col+1 ;
            cout << " | ";
        } END;
    }
    cout << " -------------"<<endl;

    // loop to take input from you//
    while (!end) {
        int move;
        if (turn == fplayer) {
           bool fill=false;
           while(fill==false) {
               cout<<"enter valid move:";
               cin>>move;
               move--;
               if(board[move]==blank)
               fill=true;
           }
        }
        else {
            cout << " cpu's move"<<endl;
            finds(turn, move);
        }

        board[move] = turn;
       
        print_matrix(); // to show the board//

        if (eval_id()==turn) {
            end=true;
            if (turn == fplayer)
                cout << "YOU Won!\n";
            else
                cout << "CPU Won!\n";
        }
        else if (Draw()) {
            end=true;
            cout << "Draw \n";
        }
        turn *= -1;
    }
   return 0;
}
int main() {
    string ans;
    while(1>0) {
        cout<<"do you want to play![yes or no]"<<endl;
        cin>>ans;
        if(ans=="yes")
            play();
        else
            break;
    }
}