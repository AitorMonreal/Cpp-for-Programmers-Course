
#include <iostream>
#include <iomanip>

class Gameboard{
        char gameSpace[4][4];
    public:
        Gameboard();
        void setGameSpace(int row, int column, char value);
        char getGameSpace(int row, int column);
        //These return a character - x, o, -
        char checkHorizontal();
        char checkVertical();
        char checkDiagonalTop();
        char checkDiagonalBottom();
        bool checkIfWinner();
        char getWinner();
        void printInfo();
        
};

Gameboard::Gameboard(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            gameSpace[i][j] = '-';
        }
    }
}

void Gameboard::setGameSpace(int row, int column, char value){
    gameSpace[row][column] = value;
}

char Gameboard::getGameSpace(int row, int column){
    return gameSpace[row][column];
}

char Gameboard::checkHorizontal(){
    int sum;
    char winner = '-';
    for(int i=0; i<4; i++){
        sum = 0;
        if(getGameSpace(i, 0) == '-'){
            continue;
        }
        for(int j=0; j<3; j++){
            if(getGameSpace(i, j) == getGameSpace(i, j+1)){
                sum += 1;
            }
        }
        if(sum == 3){
            winner = getGameSpace(i, 0);
        }
    }
    return winner;
}

char Gameboard::checkVertical(){
    int sum;
    char winner = '-';
    for(int j=0; j<4; j++){
        sum = 0;
        if(getGameSpace(0, j) == '-'){
            continue;
        }
        for(int i=0; i<3; j++){
            if(getGameSpace(i, j) == getGameSpace(i+1, j)){
                sum += 1;
            }
        }
        if(sum == 3){
            winner = getGameSpace(0, j);
        }
    }
    return winner;
}

char Gameboard::checkDiagonalTop(){
    int sum = 0;
    char winner = '-';
    for(int i=0; i<3; i++){
        if(getGameSpace(i, i) == getGameSpace(i+1, i+1)){
            sum += 1;
        }
    }
    if(sum == 3){
        winner = getGameSpace(0, 0);
    }
    return winner;
}

char Gameboard::checkDiagonalBottom(){
    int sum = 0;
    char winner;
    for(int i=0; i<3; i++){
        if(game.getGameSpace(4-i, i) == game.getGameSpace(4-(i+1), i+1)){
            sum += 1;
        }
    }
    if(sum == 3){
        winner = getGameSpace(0, 0);
    }
    return winner;
}

bool Gameboard::checkIfWinner(){
    bool win_outcome = 0;
    horizontal_win = (checkHorizontal!='-');
    vertical_win = (checkVertical!='-');
    diagonal_win = ((checkDiagonalTop!='-') | (checkDiagonalBottom!='-'));
    if(horizontal_win | vertical_win | diagonal_win){
        win_outcome = 1;
    }
    return win_outcome;
}

char Gameboard::getWinner(){
    char winner = '-';
    if(checkHorizontal!='-'){
        winner = checkHorizontal;
    }
    else if(checkVertical!='-'){
        winner = checkVertical;
    }
    else if
}

void Gameboard::printInfo(){
    std::cout << std::setw(5);
    for(int i=0; i<4; i++){
        std::cout << "\n";
        for(int j=0; j<4; j++){
            std::cout << gameSpace[i][j];
        }
    }
}
