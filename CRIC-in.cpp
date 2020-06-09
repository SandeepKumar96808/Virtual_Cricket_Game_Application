//============================================================================
// Name        : CRIC-in.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include"game.h"
using namespace std;

int main() {
	Game g;
	g.welcomeUsers();

	cout << "\nPress Enter to continue: ";
	cin.get();

	g.showAllPlayer();

	cout << "\nPress Enter to continues: ";
	cin.get();

	g.selectPlayers();

	cout << "\nPress Enter to continues: ";
	cin.get();

	//cin.ignore(numeric_limits < streamsize > ::max(), '\n');

	g.showTeamPlayers();

	//cin.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "\nPress Enter to Toss: ";
	cin.get();

	g.toss();



	cout << "\nPress Enter to Play first Inning: ";
	cin.get();

	g.startFirstInnings();

	cout << "\nPress Enter to Play first Inning: ";
	cin.ignore(numeric_limits < streamsize > ::max(), '\n');

	g.startSecondInnings();

	g.decideWinner();
	g.matchSummery();
	return 0;



}
