#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>
#include<unistd.h>
#include"team.h"

class Game{

	public:
		int playersPerTeam, maxBalls, totalPlayers;
		std::string players[11];
		bool isFirstInnings;
		Team teamA, teamB;
		Team *battingTeam, *bowlingTeam,*temp;
		Player *batsman, *bowler;
		Game();
		void welcomeUsers();
		void showAllPlayer();
		int takeIntegerInput();
		void selectPlayers();
		bool validateSelectPlayer(int);
		void showTeamPlayers();
		void toss();
		void tossChoice(Team);
		void startFirstInnings();
		void startSecondInnings();
		void initializePlayers();
		void playInnings();
		void bat();
		bool validateInningsScore();
		void showGameScorecard();
		void decideWinner();
		void matchSummery();

};
