#include "header.h"
#include <cstdlib>
#include <windows.h>

Player user;
Player computer;

void Player::addWins() {
	this->wins++;
}

int Player::checkWins() {
	return this->wins;
}

void Game::mainMenu() {
	cout << "\n\t ~ Rock Paper Scrissors ~ \n \t\t\tBy Popescu Paul\n\n ";
	
	cout << "\t\t1. Play\n\t\t2. Credits\n\t\t3. Exit";
	int choice;
	cout << "\n\n\t Choice: "; cin >> choice;
	switch (choice) {
	case 1:
		startGame();
		break;
	case 2:
		credits();
		break;
	case 3:
		cout << "\n\t Exiting...";
		Sleep(2000);
		break;
	default:
		cout << " Choice not available.";
		break;
	}
}


void Game::startGame() {
	maxWins = 0;
	cout << "\n How many games until game over? \n \t 3    5    7\n\n\tChoice: ";
	int choice; cin >> choice;
	maxWins = choice; cout << "\n You've chosen " << maxWins << " maximum wins needed.";
	cout << "\n\n\t Game starting...";
	Sleep(3000);
	system("CLS");
	RPSGame();
}

void Game::RPSGame() {
	srand((unsigned)time(NULL));

	while(user.wins < maxWins || computer.wins < maxWins) {
		cout << "\n\n\tMake your choice: ";
		cout << "\n 1. Rock \n 2. Paper \n 3. Scrissors \n \n \t Choice: ";

		/*
		the choices are:
		1. rock
		2. paper
		3. scrissors
		*/

		int choice; 
		do
			cin >> choice;
		while (choice != (int)choice);
		cout << "\n\t You chose: \n";
		switch (choice) {
		case 1:
			rock();
			break;
		case 2:
			paper();
			break;
		case 3:
			scissors();
			break;
		default:
			cout << "Choice not available.";
			break;
		}
		int computer_choice = rand() % 3 + 1;

		cout << "\n\n\t Computer chose: \n\n";
		if (computer_choice == 1) {
			rock();
			if (choice == 3) {
				cout << "\n\n\t Computer wins!\n";
				computer.addWins();
			}
			else if (choice == 2) {
				cout << "\n\n\t User wins!\n";
				user.addWins();
			}
			else
				cout << "\n Draw! Go again.";
			checkEndGame();
			Sleep(1250);
			system("CLS");
		}
		else if (computer_choice == 2) {
			paper();
			if (choice == 1) {
				cout << "\n\n\t Computer wins!\n";
				computer.addWins();
			}
			else if (choice == 3) {
				cout << "\n\n\t User wins!\n";
				user.addWins();
			}
			else
				cout << "\n Draw! Go again.";
			checkEndGame();
			Sleep(1250);
			system("CLS");
		}
		else if (computer_choice == 3) {
			scissors();
			if (choice == 2) {
				cout << "\n\n\t Computer wins!\n";
				computer.addWins();
			}
			else if (choice == 1) {
				cout << "\n\n\t User wins!\n";
				user.addWins();
			}
			else
				cout << "\n Draw! Go again.";
			checkEndGame();
			Sleep(1250);
			system("CLS");
		}
	}
	return;
}


void Game::credits() {
	system("cls");
	cout << "\n\n\n\t\tGame by Popescu Paul\n";
	cout << "\t      2nd Year Student - Math UAIC\n\n";
	cout << "\t\tThank you for playing!   \n\n\n\n";
	Sleep(5000);
	system("cls");
	mainMenu();
	//may add more
}


void Game::checkEndGame() {
	int winsU = user.checkWins();
	int winsC = computer.checkWins();
	if (winsU == maxWins) {
		cout << "User WINS!\nGame closing...";
		Sleep(2000);
		exit(0);
	}
	else if (winsC == maxWins){
		cout << "Computer WINS!\nGame closing...";
		Sleep(2000);
		exit(0);
	}
}

int main() {
	system("color E0");

	Game game;
	game.mainMenu();
	return 0;
}