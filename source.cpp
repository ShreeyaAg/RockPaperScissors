#include <iostream>

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

void chooseWinner(char uChoice, char cChoice) {
    if (uChoice == ROCK && cChoice == PAPER) {
        std::cout << "Computer Wins! Paper wraps Rock."<< std::endl;
    }
    else if (uChoice == PAPER && cChoice == SCISSORS) {
        std::cout << "Computer Wins! Scissors cut Paper."<< std::endl;
        
    }
    else if (uChoice == SCISSORS && cChoice == ROCK) {
        std::cout << "Computer Wins! Rock smashes Scissors."<< std::endl;
        
    }
    else if (uChoice == ROCK && cChoice == SCISSORS) {
        std::cout << "You Win! Paper wraps Rock."<< std::endl;
        
    }
    else if (uChoice == PAPER && cChoice == ROCK) {
        std::cout << "You Win! Paper wraps Rock."<< std::endl;
        
    }
    else if (uChoice == SCISSORS && cChoice == PAPER) {
        std::cout << "You Win! Scissors cut Paper."<< std::endl;
    }
    else{
        std::cout << "Tie. Play again win the Game." << std::endl;
    }
}

int main(){

    char uChoice;
    char cChoice;

    uChoice = getUserOption();
    std::cout << "Your choice is: " << std::endl;
    showSelectedOption(uChoice);

    std::cout << "Computer's choice is: " << std::endl;
    cChoice = getComputerOption();
    showSelectedOption(cChoice);

    chooseWinner(uChoice, cChoice);
}