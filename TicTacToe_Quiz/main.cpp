
#include "mainFunctions.cpp"

int main(){
    Gameboard game;
    bool finish = 0;
    char winner = '-';
    int row;
    int column;
    int count = 0;
    int max_turns = 8;
    
    while(count<max_turns){
    finish = game.checkIfWinner();
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
            winner = game.getWinner();
            std::cout<<"\n\nGame Won by Player "<<winner;
            break;
        }
    }
}
