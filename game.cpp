#include "game.h"
using namespace std;

Game::Game(){

	playersPerTeam=4;
	maxBalls=6;
	totalPlayers=11;

	players[0]="Sandeep";
	players[1]="Ritik";
	players[2]="Atul";
	players[3]="Aditya";
	players[4]="Priya";
	players[5]="Priyal";
	players[6]="Jagdish";
	players[7]="Saurabh";
	players[8]="Kunal";
	players[9]="Sandeep Singal";
	players[10]="Arpit";

	isFirstInnings=false;
	teamA.name ="Team-A";
	teamB.name ="Team-B";
}

void Game::welcomeUsers() {

    cout << "---------------------------------------" << endl;
    cout << "|========= CRC-IN BY SANDEEP =========|" << endl;
    cout << "|                                     |" << endl;
    cout << "|   Welcome to CRC-IN Cricket GAME    |" << endl;
    cout << "---------------------------------------" << endl;

    cout<<endl;
    cout << "------------------------------------------------" << endl;
    cout << "|==============   INSTRUCTIONS   ==============|" << endl;
    cout << "|                                              |" << endl;
    cout << "| 1.Create two teams: TeamA and TeamB          |" << endl;
    cout << "| (with 4 player each from given 11 players)   |" << endl;
    cout << "| 2.Lead the toss and decide the choice of play|" << endl;
    cout << "| 3.Each innings will be of 6 balls            |" << endl;
    cout << "------------------------------------------------" << endl;

}

void Game::showAllPlayer(){


	cout<<std::endl;

	cout << "---------------------------------------" << endl;
	cout << "|=========  Pool of Players  =========|" << endl;
	cout << "|                                     |" << endl;
	cout << "|      You can choose 4 players       |" << endl;
	cout << "---------------------------------------" << endl;

	for(int i=0; i<11; i++){
		cout<<"["<<i<<"]  "<<players[i]<<endl;
	}

}

int Game::takeIntegerInput(){

	int n;
	while(!(cin>>n)){
		cin.clear();
		cin.ignore(numeric_limits < streamsize > ::max(), '\n');
		cout<<"Invalid input! Please try again with valid input: ";
	}

	return n;
}

bool Game::validateSelectPlayer(int index){
	int n;

	vector<Player>players;

	players = teamA.players;
	n=players.size();
	for(int i=0; i<n; i++){
		if(players[i].id==index){
			return false;
		}
	}
	players = teamB.players;
		n=players.size();
		for(int i=0; i<n; i++){
			if(players[i].id==index){
				return false;
			}
		}

	return true;
}

void Game::selectPlayers(){
	cout<<endl;
	cout << "---------------------------------------" << endl;
	cout << "|====== Create Team-A and Team-B ======|" << endl;
	cout << "---------------------------------------" << endl;

	for(int i=0; i<playersPerTeam; i++){
		teamAselection:
		cout<<endl<<"Select player "<< i+1 <<"of Team A - ";
		int playerIndexTeamA = takeIntegerInput();
		if(playerIndexTeamA<0 || playerIndexTeamA>10){
			cout<<endl<<"Please select from the given players "<<endl;
			goto teamAselection;
		} else if(!validateSelectPlayer(playerIndexTeamA)){

			cout<<"Player already taken please choose another player"<<endl;
			goto teamAselection;

		}
		else{
			Player teamAPlayer;
			teamAPlayer.id = playerIndexTeamA;
			teamAPlayer.name = players[playerIndexTeamA];
			teamA.players.push_back(teamAPlayer);
		}
	}

	for(int i=0; i<playersPerTeam; i++){
		teamBselection:
			cout<<endl<<"Select player "<< i+1 <<"of Team B - ";
			int playerIndexTeamB = takeIntegerInput();
			if(playerIndexTeamB<0 || playerIndexTeamB>10){
				cout<<endl<<"Please select from the given players "<<endl;
				goto teamBselection;
			}else if(!validateSelectPlayer(playerIndexTeamB)){

				cout<<"Player already taken please choose another player"<<endl;
				goto teamBselection;

			}
			else{
				Player teamBPlayer;
				teamBPlayer.id = playerIndexTeamB;
				teamBPlayer.name = players[playerIndexTeamB];
				teamB.players.push_back(teamBPlayer);
			}
		}
}

void Game::showTeamPlayers(){
		cout<<endl;
		cout << "------------------------------\t\t------------------------------" << endl;
		cout << "|=========  Team-A  =========|\t\t|=========  Team-B  =========|" << endl;
		cout << "------------------------------\t\t------------------------------" << endl;
		for(int i=0; i<playersPerTeam;i++){
			cout << "|\t[" << i <<"]" << teamA.players[i].name <<"\t|"
				 <<"\t\t"
				 <<"|\t[" << i <<"]" << teamB.players[i].name <<"\t|"<<endl;
		}
		cout << "------------------------------\t\t------------------------------" << endl;
}

void Game::toss(){

	cout<<endl;
	cout << "---------------------------------------" << endl;
	cout << "|==========    Let's Toss   ==========|" << endl;
	cout << "---------------------------------------" << endl;
	cout<<"Tossing a coin... "<<endl;
	int randomValue;

	srand(time(NULL));
	randomValue = rand() % 2;
	switch(randomValue){
		case 0:cout<<"Team-A won the Toss"<<endl;
			   tossChoice(teamA);
			   break;

		case 1:cout<<"Team-B won the Toss"<<endl;
			   tossChoice(teamB);
		       break;
	}

}

void Game::tossChoice(Team tossWinnerTeam){

	 cout<<"Enter 1 to bat or bowl first"<<endl
	 	 <<"1. Bat"<<endl
	 	 <<"2. Bowl"<<endl;
	 int tc=takeIntegerInput();
	 cin.ignore(numeric_limits < streamsize > ::max(), '\n');
	 switch(tc){
	 	 case 1:cout<<endl<<tossWinnerTeam.name<<" Won the toss and elected to bat first"<<endl<<endl;
	 	 	 	 if(tossWinnerTeam.name.compare("Team-A")==0){
	 		 		 battingTeam=&teamA;
	 		 		 bowlingTeam=&teamB;
	 		 	 } else{
	 		 		 battingTeam=&teamB;
	 		 		 bowlingTeam=&teamA;
	 		 	}
	 	 	 	break;
	 	 case 2:cout<<endl<<tossWinnerTeam.name<<" Won the toss and elected to bowl first"<<endl<<endl;
	 	 	 	if(tossWinnerTeam.name.compare("Team-A")==0){
	 		 	 	 battingTeam=&teamA;
	 		 	 	 bowlingTeam=&teamB;
	 		 	 } else{
	 		 		battingTeam=&teamB;
	 		 		bowlingTeam=&teamA;
	 		 	 }
	 	 	     break;

	 	 default:cout<<"Wrong choice!!! Please enter again"<<endl;
	 			 tossChoice(tossWinnerTeam);
	 			 break;
	 }
}

void Game::startFirstInnings(){
	cout<<endl<<endl;
	cout<<"\t\t|||First Innings Starts|||"<<endl<<endl;
	isFirstInnings=true;
	initializePlayers();
	playInnings();

}

void Game::startSecondInnings(){
	cout<<endl<<endl;
	temp=battingTeam;
	battingTeam=bowlingTeam;
	bowlingTeam=temp;
	cout<<"\t\t|||Second Innings Starts|||"<<endl<<endl;
	isFirstInnings=false;
	initializePlayers();
	playInnings();

}

void Game::initializePlayers(){

	batsman=&battingTeam->players[0];
	bowler=&bowlingTeam->players[0];

	cout<<battingTeam->name<<" - "<<batsman->name<<" is batting "<<endl;
	cout<<bowlingTeam->name<<" - "<<bowler->name<<" is bowling "<<endl;

}

void Game::playInnings(){

	for(int i =0; i<maxBalls; i++){
		cout << "\nPress Enter to bowl... ";
		cin.get();

		cout<<"Bowling..."<<endl;
		bat();

		if(!validateInningsScore()){
			break;
		}

	}
}

void Game::bat(){

	srand(time(NULL));
	int runsScored = rand() % 7;

	batsman->runsScored=batsman->runsScored+runsScored;
	battingTeam->totalRunsScord=battingTeam->totalRunsScord+runsScored;
	batsman->ballsPlayed=batsman->ballsPlayed+1;

	bowler->ballsBowled+=1;
	bowlingTeam->totalBallsBowled+=1;
	bowler->runsGiven+=runsScored;


	if(runsScored!=0){

		cout<<endl<<bowler->name<<" to "<<batsman->name<<" " <<runsScored<< " runs!!"<<endl;
		showGameScorecard();
	} else{
		cout<<endl<<bowler->name<<" to "<<batsman->name<<" !!!  OUT  !!!"<<endl;
		battingTeam->wicketsLost+=1;
		bowler->wicketTaken+=1;

		showGameScorecard();

		int nextPlayerIndex=battingTeam->wicketsLost;
		batsman=&battingTeam->players[nextPlayerIndex];
	}

}

bool Game::validateInningsScore(){

	  if(isFirstInnings){
		  if(battingTeam->wicketsLost==playersPerTeam || bowlingTeam->totalBallsBowled==maxBalls){

			  cout<<"\t\t ||| First Innings Ends ||| "<<endl<<endl;

			  cout<<battingTeam->name<<" "<<battingTeam->totalRunsScord<<" - "
				  <<battingTeam->wicketsLost<< " ("<<bowlingTeam->totalBallsBowled
				  <<") "<<endl;
			  cout<<bowlingTeam->name<<" needs "<<battingTeam->totalRunsScord+1
				  <<" runs to win the match "<<endl<<endl;

			  return false;
		  }
	  } else{

		  if(battingTeam->wicketsLost==playersPerTeam || bowlingTeam->totalBallsBowled==maxBalls){

		  	  cout<<"\t\t ||| Second Innings Ends ||| "<<endl<<endl;

		  	  cout<<battingTeam->name<<" "<<battingTeam->totalRunsScord<<" - "
		  		  <<battingTeam->wicketsLost<< " ("<<bowlingTeam->totalBallsBowled
		  		  <<") "<<endl;

		  	  return false;
		  }

	  }

	  return true;

}

void Game::showGameScorecard(){
	cout<<"--------------------------------------------------------------"<<endl;
	cout<<battingTeam->name<<" "<<battingTeam->totalRunsScord<<" - "
		<<battingTeam->wicketsLost<< " ("<<bowlingTeam->totalBallsBowled<<")   | "<<batsman->name
		<< "   " <<batsman->runsScored <<" ("<<batsman->ballsPlayed<<")\t"
		<<bowler->name<<"  "<<bowler->ballsBowled<<" - "<<bowler->runsGiven<<" - "<<bowler->wicketTaken<<endl;
	cout<<"--------------------------------------------------------------"<<endl;


}

void Game::decideWinner() {
	cout<<endl<<endl<<endl;
	cout << "----------------------------------------------------" << endl;

    if (teamA.totalRunsScord > teamB.totalRunsScord) {
        cout << "\t\t Team A is the Winner" << endl;
    } else if (teamA.totalRunsScord < teamB.totalRunsScord) {
        cout<< "\t\t Team B is the Winner" << endl;
    } else {
        cout << "\t\t Match Draw" << endl;
    }

    cout << "----------------------------------------------------" << endl << endl;

    cout << "\t\t||  Match Ends  ||" << endl << endl;
}
void Game::matchSummery(){
		cout<<endl;
		cout << "------------------------------" << endl;
		cout << "|=========  Team-A  =========|" << endl;
		cout << "------------------------------" << endl;
		cout << "Player |\t Batting |\t Bowling" << endl;
		for(int i=0; i<playersPerTeam;i++){
			cout << "|[" << i <<"]" << teamA.players[i].name<<"\t"<<teamA.players[i].runsScored<<" ("<<teamA.players[i].ballsPlayed
				 <<")"<<"\t\t"<<teamA.players[i].ballsBowled<<"-"<<teamA.players[i].runsGiven<<"-"<<teamA.players[i].wicketTaken<<endl;

		}
		cout << "------------------------------" << endl;

		cout<<endl;
		cout << "------------------------------" << endl;
		cout << "|=========  Team-B  =========|" << endl;
		cout << "------------------------------" << endl;
		cout << "Player |\t Batting |\t Bowling" << endl;
		for(int i=0; i<playersPerTeam;i++){
			cout << "|[" << i <<"]" << teamB.players[i].name<<"\t"<<teamB.players[i].runsScored<<" ("<<teamB.players[i].ballsPlayed
				 <<")"<<"\t\t"<<teamB.players[i].ballsBowled<<"-"<<teamB.players[i].runsGiven<<"-"<<teamB.players[i].wicketTaken<<endl;

		}
		cout << "------------------------------" << endl;

}
