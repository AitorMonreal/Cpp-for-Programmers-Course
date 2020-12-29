
#include <iostream>
#include <iomanip>

class Gameboard{
        char gameSpace[4][4];
    public:
        Gameboard();
        void setGameSpace(int row, int column, char value);
        char getGameSpace(int row, int column);
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

void Gameboard::printInfo(){
    std::cout << std::setw(5);
    for(int i=0; i<4; i++){
        std::cout << "\n";
        for(int j=0; j<4; j++){
            std::cout << gameSpace[i][j];
        }
    }
}
