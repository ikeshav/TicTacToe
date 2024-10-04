#include <iostream>
#include <stdlib.h>
using namespace std;
//Array for \the board
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
//Variable Declara\tio\n
int choice;
int row,column;
char turn = 'X';
bool draw = false;

//Fu\nc\tio\n \to show \the curre\n\t s\ta\tus of \the gami\ng board

void display_board(){

    //Ra\nder Game Board LAYOU\T

    cout<<"PLAYER - 1 [X]\t PLAYER - 2 [O]\n\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[0][0]<<"  | "<<board[0][1]<<"  |  "<<board[0][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[1][0]<<"  | "<<board[1][1]<<"  |  "<<board[1][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[2][0]<<"  | "<<board[2][1]<<"  |  "<<board[2][2]<<" \n";
    cout<<"\t\t     |     |     \n";
}

//Fu\nc\tio\n \to ge\t \the player i\npu\t a\nd upda\te \the board

void player_turn(){
    if(turn == 'X'){
        cout<<"\n\tPlayer - 1 [X] turn : ";
    }
    else if(turn == 'O'){
        cout<<"\n\tPlayer - 2 [O] turn : ";
    }
    cin>> choice;

    //swi\tch case \to ge\t which row a\nd colum\n will be upda\te

    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Invalid Move";
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        //upda\ti\ng \the posi\tio\n for 'X' symbol if
        //i\t is \no\t already occupied
        board[row][column] = 'X';
        turn = 'O';
    }else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        //upda\ti\ng \the posi\tio\n for 'O' symbol if
        //i\t is \no\t already occupied
        board[row][column] = 'O';
        turn = 'X';
    }else {
        //if i\npu\t posi\tio\n already filled
        cout<<"Box already filled \n Please choose another!!\n\n";
        player_turn();
    }
    /* Ends */
    display_board();
}

//Fu\nc\tio\n \to ge\t \the game s\ta\tus e.g. GAME WO\N, GAME DRAW GAME I\N CO\N\TI\NUE MODE

bool gameover(){
    //checki\ng \the wi\n for Simple Rows a\nd Simple Colum\n
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;

    //checki\ng \the wi\n for bo\th diago\nal

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    //Checki\ng \the game is i\n co\n\ti\nue mode or \no\t
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;

    //Checki\ng \the if game already draw
    draw = true;
    return false;
}

//Program Main Method

int main()
{
    cout<<"\t\t\t T I C K -- T A C -- T O E -- G A M E\t\t\t";
    cout<<"\n\t\t\t\tFOR 2 PLAYERS\n\t\t\t";
    while(gameover()){
        display_board();
        player_turn();
        gameover();
    }
    if(turn == 'X' && draw == false){
        cout<<"\n\nCongratulations!Player with 'X' has won the game";
    }
    else if(turn == 'O' && draw == false){
        cout<<"\n\nCongratulations!Player with 'O' has won the game";
    }
    else
    cout<<"\n\nGAME DRAW!!!\n\n";
}
