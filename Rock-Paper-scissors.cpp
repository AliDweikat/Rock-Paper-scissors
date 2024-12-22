#include <iostream>

using namespace std;

enum enRPS { rock = 1, paper = 2, scissors = 3};
enum enRoundWon { draw, playerWon, computerWon};

struct stGameresults
{
    int playerWon = 0;
    int computerWon = 0;
    int draw = 0;
    int gameRounds = 0;    
};
int roundWinner (int playerChoice, int computerChoice) {
    if (playerChoice == computerChoice){ // draw case.
        return enRoundWon::draw; // returns 0.
    }else if (playerChoice == enRPS::rock && computerChoice == enRPS::scissors) {
        return enRoundWon::playerWon; // returns 1.
    }else if (playerChoice == enRPS::paper && computerChoice == enRPS::rock) {
        return enRoundWon::playerWon;
    }else if (playerChoice == enRPS::scissors && computerChoice == enRPS::paper) {
        return enRoundWon::playerWon;
    }else{
        return enRoundWon::computerWon; // returns 2.
    }
}
void printChoice(int choice) {
    switch (choice) {
    case enRPS::rock:
        cout << "rock";
        break;
    case enRPS::paper:
        cout << "paper";
        break;
    case enRPS::scissors:
        cout << "scissors";
        break;
    default:
        cout << "N/A";
        break;
    }
}

void printScoreBoard(int playerChoice, int computerChoice, int round, struct stGameresults *results) {
    cout << "__________" << "Round [" << round << "] __________" << endl;
    
    // Print player choice
    cout << "Player 1 choice : ";
    printChoice(playerChoice);
    cout << endl;

    // Print computer choice
    cout << "Computer choice : ";
    printChoice(computerChoice);
    cout << endl;

    // Determine and print round winner
    int winner = roundWinner(playerChoice, computerChoice);
    cout << "Round Winner   : ";
    
    switch (winner) {
    case 0:
        cout << "[Draw]" << endl;
        results->draw++;
        break;
    case 1:
        cout << "[Player]" << endl;
        results->playerWon++;
        break;
    case 2:
        cout << "[Computer]" << endl;
        results->computerWon++;
        break;
    default:
        cout << "[N/A]" << endl;
        break;
    }

    cout << "______________________________" << endl;
}
void playround (struct stGameresults * results) {
    for (int i = 1; i <= results->gameRounds; i ++) {
        int playerChoice;
        cout << "round [" << i << "] begins:" << endl << endl;
        cout << "youre choices are: [1] Rock, [2] Paper, [3] Sicissors ";
        cin >> playerChoice;
        cout << endl;
        printScoreBoard(playerChoice, (rand() % 3) + 1, i,  results);
    
    
    }
}
void printGameOver (struct stGameresults *results){
    cout << "\t\t_______________________________________________" << endl;
    cout << "\t\t\t *** G A M E  O V E R ***" << endl;
    cout << "\t\t_______________________________________________" << endl;
    cout << "\t\t_______________[Game Results]__________________" << endl;
    cout << "\t\tGame Rounds       : " << results->gameRounds << endl;
    cout << "\t\tPlayer 1 Won times: " << results->playerWon << endl;
    cout << "\t\tComputer Won times: " << results->computerWon << endl;
    cout << "\t\tDraw times        : " << results->draw << endl;
    if (results->playerWon > results->computerWon) {
        cout << "\t\tFinal Winner      : Player" << endl;
    }else if (results->computerWon > results->playerWon) {
        cout << "\t\tFinal Winner      : Computer" << endl;
    }else{
        cout << "\t\tFinal Winner      : Draw" << endl;
    }
    cout << "\t\t_______________________________________________" << endl;
}
void game () {
    char choice = 'y';
    stGameresults results;

    do {
        cout << "\033[2J\033[H";
        cout << "how many games would you like to play?" << endl;
        cin >> results.gameRounds;
        playround(&results);
        printGameOver(&results);
        cout << "would you like to continue y/n?" << endl;
        cin >> choice;   
        } while (choice == 'y' || choice == 'Y');
    

}


int main () {

    srand(time(NULL));

    game();

    return 0;
}