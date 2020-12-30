
#include <iostream>
#include "mainClasses.cpp"

int checkIfWinner(Gameboard game);
int checkHorizontal(Gameboard game);
int checkVertical(Gameboard game);
int checkDiagonalTop(Gameboard game);
int checkDiagonalBottom(Gameboard game);


int checkIfWinner(Gameboard game){
    bool finish = 0;
    bool diagonal_finish = 0;
    diagonal_finish = (checkDiagonalTop(game) | checkDiagonalBottom(game));
    if(diagonal_finish | checkHorizontal(game) | checkVertical(game)){
        finish = 1;
        std::cout<<diagonal_finish;
        std::cout<<checkHorizontal(game);
        std::cout<<checkVertical(game);
        std::cout<<(diagonal_finish | checkHorizontal(game) | checkVertical(game));
    }
    return finish;
}

int checkHorizontal(Gameboard game){
    bool finish = 1;
    for(int i=0; i<4; i++){
        if(game.getGameSpace(i, 0) == '-'){
            finish = 0;
            break;
        }
        else{
            for(int j=0; j<3; j++){
                if(game.getGameSpace(i, j) != game.getGameSpace(i, j+1)){
                    finish = 0;
                    break;
                }
            }
        }
    }
    return finish;
}

int checkVertical(Gameboard game){
    bool finish = 1;
    for(int j=0; j<4; j++){
        if(game.getGameSpace(0, j) == '-'){
            finish = 0;
            break;
        }
        else{
            for(int i=0; i<3; j++){
                if(game.getGameSpace(i, j) != game.getGameSpace(i+1, j)){
                    finish = 0;
                    break;
                    std::cout<<"checkVertical";
                }
            }
        }
    }
    return finish;
}

int checkDiagonalTop(Gameboard game){
    bool finish = 1;
    for(int i=0; i<3; i++){
        if(game.getGameSpace(i, i) != game.getGameSpace(i+1, i+1)){
            finish = 0;
            break;
            std::cout<<"checkDiagonalTop";
        }
    }
    return finish;
}

int checkDiagonalBottom(Gameboard game){
    bool finish = 1;
    for(int i=0; i<3; i++){
        if(game.getGameSpace(4-i, i) != game.getGameSpace(4-(i+1), i+1)){
            finish = 0;
            break;
            std::cout<<"checkDiagonalBottom";
        }
    }
    return finish;
}
