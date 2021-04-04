#include <iostream>
#define For(i,a,b) for(int i=a;i<b;i++)
#define loop(i) For(i,1,10)
#define END cout << "\n"
using namespace std;
#define blank 0  //if cell is not occupied//
#define first 1// id of first player//
#define second -1 // id of second player//
char show[] = {'o', ' ', 'x'}; //global declare//
const int N = 3;
int tictac[N*N],player,opponent;

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
        tictac[i] = blank;
}                                       

bool Draw()
{
    for (int i = 0; i < N * N; i++) 
        if (tictac[i] == blank)         // play untill a cell is empty//
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
        if (tictac[N*row]==tictac[N*row+1]&& 
            tictac[N*row+1]==tictac[N*row+2]) 
        { 
            if (tictac[N*row]==player) 
                return player; 
            else if (tictac[N*row]==opponent) 
                return opponent; 
        } 
    } 
  
    // column check//
    for (int col = 0; col<3; col++) 
    { 
        if (tictac[col]==tictac[col+3] && 
            tictac[col+3]==tictac[col+6]) 
        { 
            if (tictac[col]==player) 
                return player; 
  
            else if (tictac[col]==opponent) 
                return opponent; 
        } 
    } 
  
   // diagonal check// 
    if (tictac[0]==tictac[4] && tictac[4]==tictac[8]) 
    { 
        if (tictac[0]==player) 
            return player; 
        else if (tictac[0]==opponent) 
            return opponent; 
    } 
  
    if (tictac[2]==tictac[4]&&tictac[4]==tictac[6]) 
    { 
        if (tictac[2]==player) 
            return player; 
        else if (tictac[2]==opponent) 
            return opponent; 
    } 
  
    // Else if none of them have won then return 0 
    return 0; 
}
// a function to check all possible moves and to find the best move in this case//
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
        if (tictac[i] == blank)
        {
           // continue game and fill the cell// 
            tictac[i] = id;

            //check if the player with identity "id" win//
            if (evalid()==id)
            {
                optimalmove = i;
    
                tictac[i] = blank; // reset move to blank//
                return 1;
            }

            else
            {
              
                int temp_move; // to store best move//

                // if our opponent wins then that move is not good so it return negative score//
                int score = -1 * findout(-id,temp_move);  
                tictac[i] = blank; //reset cell to empty//

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
    return bestscore;
}

// function to show tictac board//
void present() {
    For(i, 0, 3) {
        cout << " -------------"<<endl;
        cout << " | ";
        For(j, 0, 3) {
            if(tictac[i*3 + j ] == 0) cout << "_";
            if(tictac[i*3 + j ] == 1) cout << "O";
            if(tictac[i*3 + j ] == 2) cout << "X";
            cout << " | ";
        }END;
    }
    cout << " -------------"<<endl;
}

int play()
{
    int firstplayer;
    cout << "What player would you like to be (Player 1 : X) or, Player 2 : O) [Player 1 plays first]? : ";
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
        if (turn == firstplayer)
        {
           bool fill=false;
           while(fill==false)
           {
               cout<<"enter valid move:";
               cin>>move;
               move--;
               if(tictac[move]==blank)
               fill=true;
           }
        }
        else
        {
            cout << " cpu's move"<<endl;
            findout(turn, move);
        }

        tictac[move] = turn;
       
       present(); // to show the tictac board//

        if (evalid()==turn)
        {
            end=true;
            if (turn == firstplayer)
                cout << "YOU Won!\n";
            else
                cout << "CPU Won!\n";
        }
        else if (Draw())
        {
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
            play();
        }
        else break;
    }
}