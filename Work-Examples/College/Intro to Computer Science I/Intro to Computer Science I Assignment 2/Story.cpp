/**********************************************************
 ** Program: Story.cpp
 ** Author: Stephanie Babb
 ** Date: 1/22/17
 ** Description: A baseball make your own adventure game, that
  * that gives users choices and prints out sotry pieces, and 
  * other choices, based on what they choose, except for one
  * part as a pitcher where it is randomly decided for them.
 ** Input: Takes user inputs of integers 1-3, and one string input
 ** Output: Parts of the story that match up with the user input
***********************************************************/
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(){
	int x=1;	
	int please;
	srand(time (NULL));

	while(x==1){
		cout<< "Welcome to my baseball adventure game! One day you were getting ready to watch baseball at home when..."<<endl;
		cout<< "Which coast do you prefer? Type 1 for West Coast and 2 for East Coast: ";
		cin >> please; 

		if (please == 1){
			cout<< "you find yourself sitting in the dugout of Safeco Field" <<endl;
			cout<< "You walk up to the coach. Enter 1 to ask to be put in the game. Enter 2 to ask how you got here: ";
			cin>> please;

			if(please==1){
				cout<< "You say \"Put me in coach!\" The coach looks at you for a while then says \"Okay you're playing center\""<<endl;
			} else{
				cout<< "You say \"What am I doing here?\" Suddenly a ball hits the center fielder and he has to come out of the game. The coach looks at you, \"Your in!\" he says, pushing you onto the field"<<endl; 
			}
			cout<< "You walk out to center field and wait for a ball to come and not too much later, one comes flying towards you. Enter 1 if you are nervous. Enter 2 if you are excited: ";
			cin>>please;

			if(please==1){
				cout<< "You cower at the sight, covering your head with the glove, but it just so happens your glove is directly under the path of the ball and you catch it! The crowd is silent for a moment before erupting into applause at the unusual and spectacular catch." <<endl;
			} else{
				cout<< "You are completely prepared as the ball comes your way. You jump up and grab it. The crowd goes wild for your first major league catch."<< endl;
			}
			cout << "The coach comes out with the now healthy center fielder and asks whether or not you want to stay in the game. Enter 1 for yes and 2 for no: ";
			cin >> please;

			if(please == 1){
				cout<<"You stay in the game and catch every ball that comes your way, of course the other outfielders have your back for anything out of your reach. The Mariners win the game and as you walk of celebrating with the team, the coach tells you \"Great job kid! Come back and try out for us when you're older.\" before patting you on the back and walking away"<<endl;
			} else{
				cout<<"You head back to the duggout with the coach and watch from there. It is a great game and the center fielder makes some amazing catches that you are glad you didn't have to attempt. The Mariners take a huge lead for the win, and you get to clebrate with the team"<< endl;
			}

		} else {
			cout<< "you find yourself sitting in the dugout of Fenway Park" << endl;
			cout<< "The coach looks at you and says \"What position are you playing kid?\" Enter 1 for 3rd base, enter 2 for pitcher, and enter 3 for catcher: ";
			cin>> please;
		
			if(please==1){
				cout<<"You tell the coach you want 3rd base. He sends you out there and you make stop after stop, even making a couple double plays, when suddenly a ball comes down the left foul line. Enter 1 to dive for it and 2 to run for it, but stay on your feet:  "<<endl;
				cin>>please;
			
				if (please == 1){
					cout<<"You dive for the ball and it goes rigth past your glove. Luckily, the left fielder has come in behind you and makes an incredible play to get the lead runner out."<<endl;	
				} else{
					cout<< "You run over making sure to stay steady on your feet so you can turn and make a throw. You scoop up the ball and throw it as quickly as you can to second base. The ball gets the in time to get the lead runner and the second basman turns a double play on the slow batter. The crowd goes wild!"<<endl;
				}
			
			} else if(please == 2){
				cout<<"You tell the coach that you want to pitch and head to the mound. You pitch a few inningsjust fine, but then you wind up with the bases loaded, only one out, and a 3-2 count. Enter one to throw your best pitch that you are most comfotable with. Enter 2 to throw the pitch that you think would confuse the batter, but you aren't as comfortable with: ";
				cin>>please;
			
				if (please == 1){
					cout<< "You throw your best pitch, but the batter sees it coming. He hits the ball deep into left field, where the left fielder is able to catch it for an out, but the runner on third tags to score a run."<<endl;
				} else{
					cout<<"You throw the pitch you are less comfortable with. You confuse the batter and he grounds into a double play to end the inning. The crowd goes wild!"<<endl;
				} 
			
				cout<< "It is the 9th inning. You struck the first batter out, but it took a fair amount of pitches. The coach asks you if you want to pitch a complete game."<<endl;
			 	please = fmod(rand(), 2); //Takes a random number and get remainder when devided by to so it stores 1 or 0
			
				if(please == 1){
					cout<<"You feel great! You decide to stay in the game. The next two batters are easy outs and the Red Sox win. Your teammates all congratulate you on a great first game."<<endl;
				} else{
					cout<<"Unfortionately your elbow has started to bother you. You tell him to send in the closer. The crowd gives you a standing ovation as you head into the dugout. You watch the closer do an amazing job finishing out the game, and the Red Sox win. "<<endl;
				}				

			} else{
				cout<<"You tell the coach you want to play catcher and run behind home plate. You do well guiding the pitcher and stopping balls from getting past you, in the top of the ninth, there are two outs with runners on first and third and your team only has a one run lead. The piture wants to make a risky pith that you dissagree with. Enter 1 to try and convince hime to do a pitch you like, or enter to to let him use his pitch";
				cin>> please;
			
				if(please == 1){
					cout<<"You try to convince him to go with a more reasonal pitch, but he ignores you."<<endl;
				} else{
					cout<<"You let him go with the pitch he wants to make."<<endl;
				}

				cout<<"The pitch goes horribly and gets past you. The palyer on third decides to go for it. You rush to grab the ball and tag the runner at the plate. You make it just in time to get the out and the game is over. The crowd goes wild and so do your teammates. Everyone conragtulates you on a great first game."<<endl;
			}
		} 
		cout<< "Is Baseball your favorite sport? Type 1 for yes and 2 for no: ";
		cin>> please;

		if(please==1){
			cout << "You got the entire team to sign your new jersey and were told you were welcome back for any game wanted to watch. Today was the best day ever!" << endl;
		} else{
			string test;
			cout<< "What is your favorite sport? ";
			cin>> test;
			cout<< "Today was a great day. Maybe tommorrow, it will be "<< test<<"." <<endl;
		} 
	
		cout<< "Would you like to play again? If so, enter 1, if not, enter 2: ";
		cin>>x;



	}

	cout<< "Goodbye! Thanks for playing!"<<endl;

	return 0;
}
