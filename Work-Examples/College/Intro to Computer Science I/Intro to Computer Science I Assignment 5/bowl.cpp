/************************************************************************************
 *Program Filename: bowl.cpp
 *Author: Stephanie Babb
 *Date:3/11/17
 *Description: A program that simulates bowling and prints out the scores after each player finishes a frame
 *Input: User input number of players and names
 *Output:None
 ***********************************************************************************/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

void create_arrays(int &, int&, int&,char***,int**, int ***, int ***);
void turn(int&, int &, int **, int***,char***,int***,int &);
void enter(int);
void frame_scores(char ***, int &, int &, int **,int ***, int ***, int &);
void print_delete(char***, int**, int***, int***, int &, int&, int &);
void print(char***, int **, int***, int***, int &,int &, int &);

int main(){
	int num_players;
	int current_player=1;
	int round=1;
	char **names;
	int *score;
	int **bowl;
	int **frame;
	cout<< "How many players? (Max of 5) Enter 0 to quit: ";
	cin>> num_players;
	while(cin.fail()){
		cin.clear();
		cin.ignore();
		cout<<"This is an invalid input please try again.: ";
		cin>>num_players;
	}
	while(num_players!=0){
		if (5<num_players||num_players<0){
			cin.ignore();
			cout<<"This is an invalid input. Please try again: ";
			cin>>num_players;
		}
		cin.ignore();
		if(round==1&&current_player==1){
		   	create_arrays(num_players,current_player,round,&names,&score,&bowl, &frame);
		}
		turn(current_player, round, &score, &bowl, &names, &frame, num_players);
	}
	
	return 0;
}
/******************************************************************************************
 *Function:create_arrays
 *Description:Creates array memory on the heap. Sets all int array value to 0. Takes in the players names and stores them in the names array.
 *Parameters:number of players, current player number, current round number, an array of player names, an array of the players total scores, an array of each roll the player bowls, an array of each frame score
 *Pre-conditions: All parameters must be passed properly and the arrays must have been created correctly.
 *Post-conditions: Memory is properly allocated
 *Return:None
 *****************************************************************************************/
void create_arrays(int &np, int &cp,int &round, char ***names, int **score,int ***bowl, int ***frame){
	*names=new char *[np];
	*score=new int[np];
	 *bowl=new int *[np];
	 *frame=new int *[np];
	for(int i=0; i<np; i++){
		(*names)[i]=new char[256];
		(*bowl)[i]=new int[21];
		(*frame)[i]=new int[10];
	}

	for (int i=0; i<np; i++){
		//names [i]={'\0'};
		cout<<"Enter player "<<i+1<<"'s name: ";
		cin.getline((*names)[i],256);
//		cout<<names[i]<<endl;
		(*score)[i]=0;
		for (int j=0; j<21; j++){
			(*bowl) [i][j]=0;
		}
		for(int k=0; k<10;k++){
			(*frame)[i][k]=0;
		}

	}
//	cout<<"here "<<(*bowl)[0][1]<<endl;
//	turn(cp, round, score, bowl, names, frame, np);

}
/******************************************************************************************
 *Function:turn
 *Description:Allows the current player to bowl and stores it in an array, then passes it' s information to frame_scores, increments the current player
 *Parameters:number of players, current player number, current round number, an array of player names, an array of the players total scores, an array of each roll the player bowls, an array of each frame score
 *Pre-conditions:Parameters are declared and passed correctly
 *Post-conditions: The scores are stored in the bowl array and can be accessed
 *Return:None
 *****************************************************************************************/

void turn(int &cp, int &round, int **sc, int ***b,char ***n,int ***f, int &np){
   	enter(cp);
	srand(time(NULL));
	int roll=rand()%11+0;
	int roll2=0;
	cout<<"You knocked down "<< roll<< " pins"<<endl;
	(*b)[cp-1][(round*2)-2]=roll;// throught the program things like this are used to get into base 0
	(*sc)[cp-1]=(*sc)[cp-1]+roll;
	if(roll!=10){	
	   	enter(cp);
		roll2=rand()%(11-roll)+0;
		cout<<"You knocked down "<< roll2 <<" pins"<<endl;
		(*b)[cp-1] [(round*2)-1]=roll2;
		(*sc)[cp-1]=(*sc)[cp-1]+roll2;
		cout << "Test 1" << endl;
	}
	if(round==10&&(roll+roll2==10)){
			enter(cp);
			(*b)[cp-1][20]=random()%11;
			cout<<"You knocked down "<< (*b)[cp-1][20];
			(*sc)[cp-1]=(*sc)[cp-1]+(*b)[cp-1][20];		
	}
	frame_scores(n, cp, round, sc, b, f, np);
	cp++;
	if(cp>np){
	   	round+=1;
		cp=1;
	}

}

/******************************************************************************************
 *Function: enter
 *Description: prompts the player to press enter to bowl
 *Parameters:number of players, current player number, current round number, an array of player names, an array of the players total scores, an array of each roll the player bowls, an array of each frame score
 *Pre-conditions:cp must be defined
 *Post-conditions: The turn function continues running
 *Return:None
 *****************************************************************************************/
void enter (int cp){
	char inpu='0';
	while (inpu!='\n'){
		cin.ignore();
		cout<<"Player "<<cp<<" press enter to bowl";
	        cin.get(inpu);	
	}
	
}

/******************************************************************************************
 *Function:frame_scores
 *Description:Uses the information in the bowl array to fill the frames array and calls the print function
 *Parameters:number of players, current player number, current round number, an array of player names, an array of the players total scores, an array of each roll the player bowls, an array of each frame score
 *Pre-conditions:the bowl array must have the proper information
 *Post-conditions: The printing function is called
 *Return:None
 *****************************************************************************************/
void frame_scores(char ***n , int &cp, int &round, int **sc, int ***b, int ***f, int &np){
	(*f)[cp-1][round-1]=(*b)[cp-1][round*2-1]+(*b)[cp-1][round*2-2];

	print_delete(n,sc,b,f,np,round,cp);
}

/******************************************************************************************
 *Function:Print_delete
 *Description: Prints the top of the scoreboard, calls the print function for the rest of the scoreboard, deletes the memory used for the arrays
 *Parameters:number of players, current player number, current round number, an array of player names, an array of the players total scores, an array of each roll the player bowls, an array of each frame score
 *Pre-conditions:All parametersmust be properly defined and allocated
 *Post-conditions: If it is th final play of the final round it is reset to play again
 *Return:None
 *****************************************************************************************/
void print_delete(char ***n, int **sc, int ***b, int ***f, int&np, int &round, int &cp){
   	cout<<"Name  |";
   	for (int m=1;m<22;m++){
		cout<<" "<<m<<" |";
	}
	cout<<"Score"<<endl;
	print(n,sc,b,f,np,round,cp);
	if (round==10&&cp==np){
	   	for(int i=0; i<np; i++){
			delete [] *n[i];
			delete [] *b[i];
			delete [] *f[i];
		}
		delete [] *n;
		delete [] *b;
		delete [] *f;
		delete [] *sc;
		n=NULL;
		b=NULL;
		f=NULL;
		sc=NULL;
		cout<<"Enter the number of players. Enter 0 to quit: ";
		cin>>np;
		cp=1;
		round=1;
	}
}

/******************************************************************************************
 *Function:print
 *Description: Prints the score portion of the scoreboard. On round 10 accounts for spares and strikes
 *Parameters:number of players, current player number, current round number, an array of player names, an array of the players total scores, an array of each roll the player bowls, an array of each frame score
 *Pre-conditions:All parametersmust be properly defined and allocated
 *Post-conditions: Changes values in score on final frame
 *Return:None
 *****************************************************************************************/
void print(char ***n, int **sc, int ***b, int ***f, int&np, int &round, int &cp){
  	for(int i=0; i<np; i++){
	   	cout<<"-----------------------------------------------------------------------------------------"<<endl;
	   	cout<<" "<<(*n)[i]<<" |";
		for(int j=0; j<21; j++){
		   	if((*b)[i][j]==0){
				cout<<" - ";
			}else if(j%2==1&&(*b)[i][j]+(*b)[i][j-1]==10){
			   	cout<<" / ";
				if(round==10&&i==cp-1){
					(*sc)[cp-1]=(*sc)[cp-1]+(*b)[cp-1][j+1];
				}
			}else if(j%2==0&&(*b)[i][j]==10){
			   	cout<<" X ";
				if(round==10&&j<20&&i==cp-1){
					(*sc)[cp-1]=(*sc)[cp-1]+(*f)[cp-1][(j/2)+1];
				}
			}else {
				cout<<" "<<(*b)[i][j]<<" ";}
			if(j%2!=0){
				cout<<"|";
			}
		}
		cout<<((*sc)[i])<<endl;
		cout<<"      ";
		for(int k=0;k<10;k++){
			cout<< " "<<(*f)[i][k]<<" ";
			cout<<" | ";
			
		}
		cout<<endl;
	}
 
}
