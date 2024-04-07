//want to edit this so that user can pick number of rounds being played, and it tells you the score after each round

#include <iostream>
#include <utility>

//constant var

const char ROCK = 'r';
const char PAPER = 'p';
const char SCISSORS = 's';

char getComputerOption(){
    srand(time(0));
    int num = rand() % 3 + 1;

    if(num==1) return 'r';
    if(num==2) return 'p';
    if(num==3) return 's';
}

char getUserOption(){
    char c;
    std::cout<< "Let's play Rock, Paper, Scissors!" << std::endl;
    std::cout<< "Choose one of the following options: " << std::endl;
    std::cout<< "-------------------------------------" << std::endl;
    std::cout<< "(r) for rock, (p) for paper, (s) for scissors" << std::endl;
    std::cin >> c;

    while( c != 'r' && c!= 'p' && c!='s'){
        std::cout << "please enter one of the following options only:" << std::endl;
        std::cout << "(r) for rock, (p) for paper, (s) for scissors" << std::endl;
        std::cin >> c;
    } 

    return c;
}

void showSelectedOption(char option){
    if (option == 'r') std::cout << "Rock" << std::endl;
    if (option == 's') std::cout << "Scissors" << std::endl;
    if (option == 'p') std::cout << "Paper" << std::endl;

}

int chooseWinner(char uChoice, char cChoice){

    if((uChoice == ROCK && cChoice == SCISSORS) || (uChoice == PAPER && cChoice == ROCK) || (uChoice == SCISSORS && cChoice == PAPER)){
        std::cout << "You win this round! \n";
        return 1; 
    }
    else if( uChoice == cChoice){
        std::cout << "It's a tie, try again. \n";
    }
    else{
        std::cout << "Computer wins this round! \n";
        return -1;
    }
}

int selectNumberRounds (int n){
    std::cout << "Please select an odd number of rounds you want to play out of:" << std::endl;
    std::cin >> n;

    while(n % 2 == 0){
        std::cout << "You have entered an even number of rounds. Please enter an odd number." << std::endl;
        std::cin >> n;
    }   

    int bestOf;
    bestOf = (n + 1)/2;

    std::cout << "First to " << bestOf << " wins." << std::endl;
    return bestOf;

}

std::pair<int, int> playGame(int rounds){
    
    int youScore = 0;
    int compScore = 0;

    for(int i = 0; i < rounds; ++i){
        char uChoice = getUserOption();
        char cChoice = getComputerOption();

        std::cout << "Your choice is: ";
        showSelectedOption(uChoice);
        std::cout << "Computer's choice is: ";
        showSelectedOption(cChoice);

        int winner = chooseWinner(uChoice, cChoice);
        if(winner == 1){
            youScore ++;
        }
        else if(winner == -1){
            compScore ++;
        }
        }

    return std::make_pair(youScore, compScore);
    
}   


int main(){

    int rounds;
    int bestOf = selectNumberRounds(rounds);

    if (bestOf != -1){
        std::pair<int, int> scores = playGame(bestOf);

        std::cout<< "Scores for game: \n";
        std::cout << "You: " << scores.first << ", Computer: " << scores.second << std::endl;
        }   

    }