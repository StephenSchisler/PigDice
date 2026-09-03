#include <iostream>
#include <ctime>
#include <cstdlib>

// Build your solution starting from this code.

struct GameState {
    char choice;
    int turn_count = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;
};

void take_turn(GameState &mg); // prototype statements starts here
void play_game(GameState &mg); // note: with "&" makes it a reference variable
void roll(GameState &mg); // reference varibles give an address insted of copys of the variable
void hold(GameState &mg); // ends here

int main() {
    GameState my_game; // instantiate a GameState object
    std::cout << "Let's Play PIG Dice!\n" << std::endl;
    std::cout << "* See how many turns it takes you to get to 20 points." << std::endl;
    std::cout << "* Turn ends when you hold or roll a 1." << std::endl;
    std::cout << "* If you roll a 1, you lose all points for the turn." << std::endl;
    std::cout << "* If you hold, you bank all points for the turn to the game score\n" << std::endl;
    play_game(my_game); // call the play_game function and pass the GameState object
    return 0;
}



void play_game(GameState &mg) {
    while (!mg.game_over){
        take_turn(mg); // 1st,  take your the turn
        mg.game_score += mg.score_this_turn; // alter values to mach the turns result
        if (mg.game_score >= 20) { // check if the goal score has been reached
            mg.game_over = true;
        }
        else {
            mg.turn_over = false;
            mg.score_this_turn = 0;
        }
    }
    std::cout << "You finished wih a final score of " << mg.game_score << " in " << mg.turn_count << " turns!" << std::endl;
    std::cout << "Thanks for playing PIG Dice!" << std::endl;
}
void take_turn(GameState &mg) {
    mg.turn_count++; // means the same thing as mg.turn_count = mg.turn_count + 1
    std::cout << "TURN " << mg.turn_count << " - Game Score: " << mg.game_score;
    while (!mg.turn_over) {
        std::cout << "\nroll or hold? (r/h): " ;//<< std::endl;
        std::cin >> mg.choice;
        if (mg.choice == 'r') {
            roll(mg);
        }
        else if (mg.choice == 'h') {
            hold(mg);
        }
        else {
            std::cout << "Invalid choice!"<< std::endl;
        }

    }
    std::cout << "Score Banked This Turn: " << mg.score_this_turn << "\n" << std::endl;
}

void roll(GameState &mg) {
    srand(time(NULL));
    int die = rand() % 6 + 1;
    std::cout << "Die: " << die;
    if (die == 1) {
        std::cout << "\nTurn over. No score.";
        mg.score_this_turn = 0;
        mg.turn_over = true;
    }
    else {
        mg.score_this_turn += die;
        std::cout << " - Running score this turn: " << mg.score_this_turn;
    }
}

void hold(GameState &mg) {
    mg.turn_over = true;
}