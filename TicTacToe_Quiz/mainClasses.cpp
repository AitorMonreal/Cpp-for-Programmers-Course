
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
    int sum = 0;
    char winner = '-';
    for(int i=0; i<4; i++){
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
    int sum = 0;
    char winner = '-';
    for(int j=0; j<4; j++){
        if(getGameSpace(0, j) == '-'){
            continue;
        }
        for(int i=0; i<3; j++){
            if(getGameSpace(i, j) == getGameSpace(i+1, j)){
                sum += 1;
                }
            }
        }
        if(sum == 3){
            winner = getGameSpace(0, j);
        }
    }
    return winner;
}

char Gameboard::checkDiagonalTop(){
    char winner;
    for(int i=0; i<3; i++){
        if(game.getGameSpace(i, i) != game.getGameSpace(i+1, i+1)){
            finish = 0;
            break;
            std::cout<<"checkDiagonalTop";
        }
    }
    return winner;
}

char Gameboard::checkDiagonalBottom(){
    char winner;
    for(int i=0; i<3; i++){
        if(game.getGameSpace(4-i, i) != game.getGameSpace(4-(i+1), i+1)){
            finish = 0;
            break;
            std::cout<<"checkDiagonalBottom";
        }
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
