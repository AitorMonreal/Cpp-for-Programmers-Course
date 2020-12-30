
#include "mainFunctions.cpp"

int main(){
    Gameboard game;
    bool finish = 0;
    int row;
    int column;
    int count = 0;
    int max_turns = 8;
    
    finish = checkIfWinner(game);
    while(count<max_turns){
        if(finish == 0){
            count += 1;
            std::cout << "\n\n\nX player:\n- Enter row:\n";
            std::cin >> row;
            std::cout << "- Enter column:\n";
            std::cin >> column;
            game.setGameSpace(row, column, 'x');
            std::cout << "O player:\n- Enter row:\n";
            std::cin >> row;
            std::cout << "- Enter column:\n";
            std::cin >> column;
            game.setGameSpace(row, column, 'o');
            game.printInfo();
        }
        else{
            std::cout<<"Game Won";
            break;
        }
    }
}
