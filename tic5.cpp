#include<iostream>
using namespace std;


  int board[5][5];
 char currentPlayer = 'x';
 void intiborad(){
  for(int i=0;i<5;i++){
    for(int j = 0;j<5;j++){
        board[i][j] = 1+ i*5 + j;
    }
  }
 }



    void printBoard(){
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            if(board[i][j]>=1 && board[i][j]<=10){
            cout<<" "<< board[i][j]<< "  ";
            }else{
                cout<<" "<< board[i][j]<< " ";
                 }
            if(j<4){
                cout<<"|";
                    }
                            }
         if(i<4){
                cout<<"\n----|----|----|----|----\n";
                }
                          }
                    }

bool switchplayer(){
    currentPlayer = currentPlayer =='x'? 'o':'x';
}
bool checkwinner(){
  for(int i = 0;i<5;i++){
   if (board[i][0] == board[i][1] && board[i][1] == board[i][2]  && board[i][2] && board[i][3] && board[i][3] && board[i][4]) {return true;} // Row
   if (board[0][i] == board[1][i] && board[1][i] == board[2][i]  && board[2][i] && board[3][i] && board[3][i] && board[4][i]){ return true;}  // Column
}

  if (board[0][0] == board[1][1] && board[1][1] ==  board[2][2] && board[2][2] == board[3][3] && board[4][4] ) {return true;}
  if (board[0][4] == board[1][3] && board[1][3] ==  board[2][2] && board[2][2] == board[3][1] && board[4][0] ) {return true;}

  return false;
}


// Function to check if the board is full (draw)
bool checkDraw() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;  // Still empty spots
            }
        }
    }
    return true;  // No empty spots left
}

// Function to play the game
void playGame() {
    int choice;
    bool gameOver = false;

    while (!gameOver) {
        printBoard();  // Display the board

        // Get player input
        cout << "\nPlayer " << currentPlayer << ", enter your move (1-25): ";
        cin >> choice;

        // Convert choice to grid coordinates
        int row = (choice - 1) / 5;
        int col = (choice - 1) % 5;

        // Check if the chosen cell is available
        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = currentPlayer;  // Place the player's mark

            // Check if we have a winner
            if (checkwinner()) {
                printBoard();
                cout << "\nPlayer " << currentPlayer << " wins!\n";
                gameOver = true;
            }
            // Check if it's a draw
            else if (checkDraw()) {
                printBoard();
                cout << "\nIt's a draw!\n";
                gameOver = true;
            } 
            else {
                switchplayer();  // Switch player if no win/draw
            }
        } else {
            cout << "\nInvalid move! Cell already occupied.\n";
        }
    }
}


int main(){
    intiborad();
    playGame();


    return 0;
}