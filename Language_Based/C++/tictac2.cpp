#include<iostream>

#define For(i,a,b) for(int i=a;i<b;i++)
#define loop(i) For(i,1,10)
#define END cout << "\n"
#define blank -1  //if cell is not occupied//
#define first 100// id of first player//
#define second 10 // id of second player//
char show[] = {'O', ' ', 'X'}; //global declare//
const int N = 3;
int arr[N*N],player,opponent;
using namespace std;


int findout(int id, int &optimalmove);

void print_board() {
    For(i, 1, 10) cout<< arr[i] << " ";END;
    For(i, 0, 3) {
        cout << " -------------"<<endl;
        cout << " | ";
        For(j, 0, 3) {
            if(arr[i*3 + j ] == -1) cout << "_";
            if(arr[i*3 + j ] == 10) cout << "O";
            if(arr[i*3 + j ] == 100) cout << "X";
            cout << " | ";
        }END;
    }
    cout << " -------------"<<endl;
}

bool check_win() {
    For(i, 0, 3) {
        if( (arr[0+i] == arr[3+i] == arr[6+i]) && (arr[0+i] != -1) ) return 1;
    }
    For(i, 0, 3) {
        if( (arr[0+i*3] == arr[1+i*3] == arr[2+i*3]) && (arr[0+i*3] != -1) ) return 1;
    }
    if( (arr[0] == arr[4] == arr[8]) && (arr[0] != -1) ) return 1;
    if( (arr[2] == arr[4] == arr[6]) && (arr[2] != -1) ) return 1;
    return 0;
}

void assignplayers(int firstplayer)
{
    if(firstplayer==1)
    player=1,opponent=-1;
    else
    player=-1,opponent=1;

}
void refillBoard() // ----------->>>>>> to make all cells unoccupied //           
{
    for (int i = 0; i < N * N; i++)      
        arr[i] = blank;
}                                       

bool Draw()
{
    for (int i = 0; i < N * N; i++) 
        if (arr[i] == blank)         // play untill a cell is empty//
            return false;

    return true;                 
}

// to check whether player has won or opponent has won//
// this function return 0 if game becomes draw//

int evalid()
{
    // row check//
   for (int row = 0; row<3; row++) 
    { 
        if (arr[N*row]==arr[N*row+1]&& 
            arr[N*row+1]==arr[N*row+2]) 
        { 
            if (arr[N*row]==player) 
                return player; 
            else if (arr[N*row]==opponent) 
                return opponent; 
        } 
    } 
  
    // column check//
    for (int col = 0; col<3; col++) 
    { 
        if (arr[col]==arr[col+3] && 
            arr[col+3]==arr[col+6]) 
        { 
            if (arr[col]==player) 
                return player; 
  
            else if (arr[col]==opponent) 
                return opponent; 
        } 
    } 
  
   // diagonal check// 
    if (arr[0]==arr[4] && arr[4]==arr[8]) 
    { 
        if (arr[0]==player) 
            return player; 
        else if (arr[0]==opponent) 
            return opponent; 
    } 
  
    if (arr[2]==arr[4]&&arr[4]==arr[6]) 
    { 
        if (arr[2]==player) 
            return player; 
        else if (arr[2]==opponent) 
            return opponent; 
    } 
  
    // Else if none of them have won then return 0 
    return 0; 
}



int play()
{
    int firstplayer;
    cout<<"to move first : 1"<<endl;
    cout<<"to move second: -1"<<endl;
    cin >> firstplayer;
    assignplayers(firstplayer);// assign you and CPU an identity//

    refillBoard(); // intialise tic-tac-toe board //

    int turn = first; 
    bool end = false;  
    
    // to show the numbering of cells//
    cout<<"these are the cell numbers"<<endl;
     for (int row = 0; row< N; row++)
    {
        for (int col = 0; col < N; col++)
            cout << "|" <<N*row+col+1<< "|";
        cout<<endl;
         for (int col = 0; col< N; col++)
         cout<<"---";
         cout<<endl;
    }

    // loop to take input from you//
    while (!end)
    {
        int move;
        if (turn == firstplayer) {
           bool fill=false;
           while(fill==false) {
               cout<<"enter valid move:";
               cin>>move;
               move--;
               if(arr[move]==blank)
               fill=true;
           }
        }
        else {
            cout << " cpu's move"<<endl;
            findout(turn, move);
        }

        arr[move] = turn;
       
        print_board(); // to show the arr board//

        if (evalid()==turn) {
            end=true;
            if (turn == firstplayer)
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
    int t;
    while(1) {
        cout << "Do you want to play? [Press 1 to continue, 0 to exit] : ";
        cin >> t;
        if(t == 1) {
            arr[0] = 0;
            For(i, 1, 10) arr[i] = -1;
            print_board();
            while(!(t == 1 || t== 2)) {
                cout << "What player would you like to be (Player 1 : X) or, Player 2 : O) [Player 1 plays first]? : ";
                cin >> t;
            }
            play();
        }
        else break;
    }

}

int findout(int id, int &optimalmove)
{
   // if game is draw//
    if (Draw())
    return 0;

    int bestscore = -2;

    // check all cell in the board//
    for (int i = 0; i < N * N; i++)
    {
        // if cell is empty//
        if (arr[i] == blank)
        {
           // continue game and fill the cell// 
            arr[i] = id;

            //check if the player with identity "id" win//
            if (evalid()==id)
            {
                optimalmove = i;
    
                arr[i] = blank; // reset move to blank//
                return 1;
            }

            else
            {
              
                int temp_move; // to store best move//

                // if our opponent wins then that move is not good so it return negative score//
                int score = -1 * findout(-id,temp_move);  
                arr[i] = blank; //reset cell to empty//

                if (score == 1)
                {
                    optimalmove = i;
                    return 1;
                }
                else if (score > bestscore)
                {
                    bestscore = score;
                    optimalmove = i;
                }
            }
        }
    }
    cout << "optimal move: " << optimalmove <<endl;
    return bestscore;
}