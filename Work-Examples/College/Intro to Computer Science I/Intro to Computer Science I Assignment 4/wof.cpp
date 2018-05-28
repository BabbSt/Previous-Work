/**********************************************************************************
 ** Program Filename: wof.cpp
 ** Author: Stephanie Babb
 ** Date: 2/19/17
 ** Description: A program that plays a game like wheel of fortune where the a user 
  *enters a message that is printed out as dashes and the players may spin, buy a 
  *vowel or attempt to solve in order to guess the message
 ** Input: Various user input of the puzzle, menue selections, and letter/puzzle guesses
 ** Output: None
 *********************************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <locale>
#include <ctime>

using namespace std;

//void get_string(string *);
int set_replace_string(string, string *);
void turn(int,string, string &, int *, int *&, int, int *, int *, int *, int *);
void guess_a_letter(string, string &, int *&, int, int*&, int, int *&, int *&, int *&);
void guess_a_vowel(string, string &, int *&, int*&, int, int *&, int *&, int *&);
void spin(int *&, string, string &, int *&, int, int *&, int *&, int *&);
void solve(int *&, int *&, string, int *, int, int *&, int *&, int *&);
void lose_a_turn(int *&, int *&, int, int *&, int *&, int *&);
void final_scores(int, int *, int *, int *, int *, int *, int *, int, int);
void print_scores(int, int, int, int, int, int);
void reset_scores(int *&, int *&, int *&, int);
void clear_input();

int main(){
	int players;
	int rounds;
	string puzzle;
	string dashes;
	int p1score=0;
	int p2score=0;
	int p3score=0;
	int p1game=0;
	int p2game=0;
	int p3game=0;
	int *score = &p1score;
	int solved;
	int currentp=1;
	int letters;
	
	cout<<"How many players are there?: ";
	cin>>players;
	cout<<"How many rounds do you want to play?: ";
	cin>>rounds;
	//cout<<rounds<<endl;	
	while(rounds>0){
		solved=0;	   
		cin.ignore();
		cout<<"Enter the puzzle: ";
		getline(cin, puzzle);	
		letters=set_replace_string(puzzle, &dashes); // gets the number of letters in the puzzle and creates a dashed version of the puzzle
		system("clear");
		rounds=rounds-1;	
		while (solved==0){ //the while loop that defines a round, once the puzzle is solved, a round is over
			turn(letters, puzzle, dashes, &currentp, score, players, &p1score, &p2score, &p3score, &solved);
		}
		final_scores(currentp, &p1score, &p2score, &p3score, &p1game, &p2game, &p3game, players, rounds);

	}

	return 0;
}

/**************************************************
 * Function: Turn
 * Description: Prints out the menu options, and takes the user's resonse. I the resonse is not acceptable, and error is printed out.
 * Parameters: the number of letters in the puzzle, the puzzle, the dashed version of the puzzle, the current player number, the round score of the current player, the number of players, player one's round score, player two's round score, player three's round score, weather or not the puzzle is solved stored as 1/0.
 * Pre-conditions: all parameters must be defined and have a value, score must be directed to the correct player's round score
 * Post-conditions: functions will be called that will change the player's score
 * Return: None
 *************************************************/
void turn(int l, string s, string &d, int *cp, int *&score, int p, int *p1, int *p2, int *p3, int *solved){
	int response;
   	cout<<"The puzzel is: "+d<<" There are "<<l<<" letters"<<endl; //prints the dashed version of the puzzle
	cout<<"Player " <<*cp<< " do you want to spin(1), solve the puzzle(2), or buy a vowel(3): ";
	cin>>response;
	if(response==1){
		spin(score,s, d, cp, p, p1, p2, p3);
	}else if (response==2){
		solve(score, cp, s, solved, p, p1, p2, p3);
	}else if (response==3){
		if(*score<10){
			cout<<"Im sorry, you do not have enough money to buy a vowel. Please select another option."<< endl;
		}else{
			guess_a_vowel(s, d, score, cp, p, p1, p2, p3);
		}
	}else{
		cout<<"This is not a valid response. Please try again."<<endl;
		clear_input();
	}
	
}

/**************************************************
 * Function: clear_input
 * Description:the error handling for a non int input in the menu
 * Parameters: None
 * Pre-conditions: The function is called if the input isn't an int
 * Post-conditions: None
 * Return: None
 *************************************************/

void clear_input(){
	cin.clear();
	cin.ignore();
}

/**************************************************
 * Function: set_replace_string
 * Description: Takes the puzzle and turns it into the disguised dashed version, counting the number of letters
 * Parameters: the puzzle and the address for the dashed version of the puzzle
 * Pre-conditions: the variables passed are created, and d is passed as an address
 * Post-conditions: dashes stores the dashed version of the puzzle
 * Return: The number of letters in the puzzle
 *************************************************/
int set_replace_string(string s, string *d){
	string temp;
	int x=0;
	for (int i=0; i<s.length(); i++){
		if (s[i]!=' '){
			temp.append("_"); //if the character in the string index isn't a space, a dash is added to the new string
			x++;	
		}else {
			temp.append(" ");
		}
	}
	*d=temp;
	return x;
}

/**************************************************
 * Function: guess_a_letter
 * Description: The player can guess a consonant, if they guess a letter that is not in the puzzle they lose a turn, if they guess a letter in the puzzle there score is increased and the letter shows up in the dashed version of the puzzle, if they give a vowel instead of a consonant they must spin again
 * Parameters: the puzzle, the dashed version of the puzzle, the current player number, the number the player spun, the round score of the current player, the number of players, player one's round score, player two's round score, player three's round score
 * Pre-conditions: all parameters must be defined and have a value, score must be directed to the correct player's round score, the spin number is 0< <21
 * Post-conditions: The player's score will increase or a function will be called to change the current player
 * Return: None
 *************************************************/
void guess_a_letter(string s, string &d, int *&score, int spin_num, int *&cp,int p, int *&p1, int *&p2, int *&p3){
	char g;
	locale loc; //used to put the letters into lowercase 
   	cout<<"Enter a charachter: ";
	cin>>g;
	int x=0;

	if(g=='a'||g=='e'||g=='i'||g=='o'||g=='u'){
		cout<<"This is not a consonant. Please respin and try again."<<endl; //error handling for non-consonant letters
	}
	else if(g!='a'){//this is the only way the else would execute
		for (int j=0; j<s.length(); j++){
			if (tolower(s[j], loc)==tolower(g, loc)){ //puts the letters into lowercase so case does not affect the guess
				d[j]=g;
				x++;		
			}	
		}	
		cout<<"There are "<< x<<" "<<g <<"s"<<endl;
		if(x==0){
			lose_a_turn(score, cp, p, p1, p2, p3);
		}else{
			*score=*score+(x*spin_num);
			cout<<"Your round score is "<< *score<<endl;
		}
	}

}

/**************************************************
 * Function: guess_a_vowel
 * Description: the user may guess a vowel, their score is decreased by ten if they guess a vowel, if they do not guess a vowel they are told it is not a vowel and to try again, but are not charged, if the vowel is in the puzzle it appears in the dashes
 * Parameters: the puzzle, the dashed version of the puzzle, the current player number, the round score of the current player, the number of players, player one's round score, player two's round score, player three's round score
 * Pre-conditions: all parameters must be defined and have a value, score must be directed to the correct player's round score
 * Post-conditions: the player's score will decrease
 * Return: None
 *************************************************/
void guess_a_vowel(string s, string &d, int *&score, int *&cp,int p, int *&p1, int *&p2, int *&p3){
	char g;
	locale loc;//used to get the string into lower case
   	cout<<"Enter a vowel: ";
	cin>>g;
	int x=0;
		
	if(g=='a'||g=='e'||g=='i'||g=='o'||g=='u'){
		*score=*score-10;
		cout<< "There are "<<x<< " "<<g <<"s"<<endl;
		cout<< "Your round score is "<<*score<<endl;
		for (int j=0; j<s.length(); j++){
			if (tolower(s[j], loc)==tolower(g, loc)){ //puts characters into lowercase so they can be compared, no matter what case they are
				d[j]=g;
				x++;		
			}	
		}
	}
	else if(g!='a'){//this is the only way the else would execute, error handling for non-vowel letter
	   	cout<<"This is not a vowel, please try again."<<endl;
	}
}

/**************************************************
 * Function: spin
 * Description: A random number between 0 and 21 is selected, if it is 21 the player looses a turn, it is zero their round score becomes zero and they lose a turn, if it is niether the value is sent to where they guess a letter so it can be multiplied by the number of correct letters they guess
 * Parameters: the puzzle, the dashed version of the puzzle, the current player number, the round score of the current player, the number of players, player one's round score, player two's round score, player three's round score
 * Pre-conditions: all parameters must be defined and have a value, score must be directed to the correct player's round score
 * Post-conditions: functions will be called that will change the player's score or change the value of current player
 * Return: None
 *************************************************/
void spin(int *&score, string s, string &d, int *&cp, int p, int *&p1, int *&p2, int *&p3){
	srand(time(NULL));
	int spin_num = rand() %	22 + 0;
	cout<< "You spun a "<< spin_num<<endl;
	if(spin_num==0){
	   	*score=0;  //the player goes bankrupt
		lose_a_turn(score, cp, p, p1, p2, p3);
	}else if(spin_num==21){
		lose_a_turn(score, cp, p, p1, p2, p3);
	}else{
		guess_a_letter(s, d, score, spin_num, cp, p, p1, p2, p3);		
	}
}

/**************************************************
 * Function: solve
 * Description: The user may attempt to guess, if they guess right the puzzle is solved, if they guess wrong they lose a turn
 * Parameters: the puzzle,the current player number, the round score of the current player, the number of players, player one's round score, player two's round score, player three's round score, weather or not the puzzle is solved stored as 1/0.
 * Pre-conditions: all parameters must be defined and have a value, score must be directed to the correct player's round score
 * Post-conditions: solved might be true which will end the round
 * Return: None
 *************************************************/
void solve(int *&score, int *&cp, string s, int *solved, int p, int *&p1, int *&p2, int *&p3){
	string guess;
	bool equal=true;
	locale loc;//used for making charachters lowercase
	cout<< "What do you think the puzzle is?: ";
	cin.ignore();
	getline(cin,guess);

	for(int i=0; i<s.length(); i++){
		if(tolower(guess[i],loc)!=tolower(s[i],loc)){// checks if the lowercase versions of the puzzle and guess are equal, so case is ignored
			equal=false;
		}
	}
	if (equal){
		cout<<"Congratulations! You are correct."<<endl;
		*solved=1;// ends the while loop, ending the round
	}else{
		cout<<"Im sorry that is incorrect."<<endl;
		lose_a_turn(score,cp,p, p1, p2, p3);
	}
}


/**************************************************
 * Function: lose a turn
 * Description: Changes the current player and adjusts what player score is being changed accordingly
 * Parameters: the current player number, the round score of the current player, the number of players, player one's round score, player two's round score, player three's round score
 * Pre-conditions: all parameters must be defined and have a value, score must be directed to the correct player's round score, and current player bust be correct
 * Post-conditions: the current player and the value stored in the pointer score will be changed
 * Return: None
 *************************************************/
void lose_a_turn(int *&score, int *&cp, int p, int *&p1, int *&p2, int *&p3){
	*cp+=1;
	if(*cp>p){
		*cp=1;// the player is increased by one, if it is the last player, it goes back to one
	}
	if(*cp==1){   //the pointer of the round score is set to the new correct player
	   	score=p1;
	}else if (*cp==2){
	   	score=p2;
	}else{
	   	score=p3;
	}
	cout<< "Player "<< *cp<< "s turn"<<endl;
}

/**************************************************
 * Function:final_scores
 * Description: Adds the round score to the winning players game score and calls functions to set the round score back to zero and to print out the players current game score
 * Parameters: the current player, playr 1s round score, player 2s round score, player 3s round score, player 1s game score, player 2s game score, player 3s game score, the number of players, the number of rounds left
 * Pre-conditions: all values must be defined and correctly kept track of throughout the rounds
 * Post-conditions: changes the game score of the winning player and calls a function to change the round scores to 0
 * Return: None
 *************************************************/
void final_scores(int cp, int *p1, int *p2, int *p3, int *p1g, int *p2g, int *p3g, int p, int r){
	if(cp==1){//if player one wins
		*p1g+=*p1;
		*p2g+=0;
		*p3g+=0;
	}else if(cp==2){//if player two wins
		*p1g+=0;
		*p2g+=*p2;
		*p3g+=0;	
	}else{		//if player three wins
		*p1g+=0;
		*p2g+=0;
		*p3g+=*p3;
	}
	print_scores(cp, *p1g, *p2g, *p3g, p, r);
	if(r!=0){
	reset_scores(p1, p2, p3,p);}
}

/**************************************************
 * Function:print_scores
 * Description: Prints out what player has one the game and all of the players current game scores. If the game is over, it prints who won the game
 * Parameters: The current player, the game score of player 1, the game score of player 2, the game score of player 3, the number of players, the number of rounds left
 * Pre-conditions: all values must be defined and correctly adjusted throughout the game
 * Post-conditions:None
 * Return: None
 *************************************************/
void print_scores(int cp, int p1g, int p2g, int p3g, int p, int r){
	cout<< "Player "<< cp<< " wins this round."<<endl;
   	cout<< "Player 1s score: $"<<p1g<<endl;
   	if(p>=2){
		cout<<"Player 2s score: $"<<p2g<<endl;
		if (p==3){
			cout<<"Player 3s score: $"<<p3g<<endl;
		}
	
	}
	if(r==0){
		if(p3g>p2g&&p3g>p1g){
			cout<<"Player 3 wins the game!"<<endl;
		}else if(p2g>p1g){
			cout<< "Player 2 wins the game!"<<endl;
		}else{
			cout<< "Player 1 wins the game!"<< endl;
		}
	}
}

/**************************************************
 * Function: reset_scores
 * Description: The player's round scores are reset to zero for a new round
 * Parameters: the pointer of player ones round score, the pointer of player twos round score, the pointer of player threes round score, the number of players
 * Pre-conditions: The values of the parameters must be passed correctly
 * Post-conditions: The players round scores equal zero
 * Return: None
 *************************************************/
void reset_scores(int *&p1, int *&p2, int *&p3, int p){
	*p1=0;
	if(p>=2){
		*p2=0;
		if(p==3){	
			*p3=0;
		}
	}
}
