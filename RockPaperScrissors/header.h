#include <iostream>
using namespace std;

class Player {
private:
	int wins;

public:
	Player() {
		wins = 0;
	}
	void addWins();
	int checkWins();
	friend class Game;
};

class Game {
private:
	//
public:
	void mainMenu();
	void startGame();
	void checkEndGame();
	void RPSGame();
	void credits();
	int maxWins;
};

void scissors() {
	cout << R"(
       _______
   ---'   ____)____
             ______)
          __________)
         (____)
   ---.__(___))";
}

void paper() {
	cout << R"(
        _______
   ---'    ____)____
              ______)
             _______)
            _______)
   ---.__________))";
}

void rock() {
	cout << R"(
       _______
   ---'   ____)
         (_____)
         (_____)
         (____)
   ---.__(___))";
}