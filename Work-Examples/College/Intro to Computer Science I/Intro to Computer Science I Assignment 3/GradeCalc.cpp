/***********************************************************
 ** Program: Grade_Calc.cpp
 ** Author: Stephanie Babb
 ** Date: 2/4/17
 ** Description: Using a combination of four function the user can
  * choose to calculate sections of their class grade, or their
  * overall grade. 
 ** Input: Various instances of user inputs of ints and doubles
 ** Output: None
 ***********************************************************/

#include <iostream>
#include <string>

using namespace std;

double LAT (string);
double recitation();
double weight_Average(string, double);
void classF();

int main(){
	cout<< "Welcome to the grade calculator"<< endl;
	int i;
	do{
		cout<< "What average would you like to calculate? Enter 1 for lab, 2 for assignments, 3 for recitation, 4 for tests, 5 for the class, or 0 to quit: ";
		cin>>i;
		if(i==1){
			cout<< "Your Lab score is "<<LAT("Lab")<<endl;
		}else if(i==2){
			cout<< "Your Assignments score is "<<LAT("Assignment")<<endl;
		}else if(i==4){
			cout<< "Your Tests score is "<<LAT("Test")<<endl;
		}else if(i==3){
			cout<<"Your Recitation score is "<<recitation()<<endl;
		}else if(i==5){
			classF();
		}else if(i!=0){
			cout<< "That is and invalid input. Please try again."<< endl;
		}
	}while(i!=0);
	
	return 0;
}

/*********************************************************************  
  ** Function: LAT 
  ** Description: Takes a string, then uses user input to calculate the
   *users grade in the Lab, Assignment, or Test catagories
  ** Parameters:  String of the catagory to calculate
  ** Pre-Conditions: None
  ** Post-Conditions:  None
  ** Return: The average score the user has recieved in the catagory as a double
  *********************************************************************/ 
double LAT(string t){
	int num;
	int yn;
	double score;
	double total=0.0;
	cout<<"How many "<< t<< "s?: ";
	cin>>num;
	cout<<"Do the points vary? Enter 0 for no and 1 for yes: ";
	cin>>yn;
	if(yn==0){
		cout<<"How many points is each worth?: ";
		cin>>yn;
		for(int i=1; i<=num; i++){
			cout<<"How many points did you recieve on "<< t<<" "<<i<<"?: ";
			cin>>score;
			total+=score/yn*100;
		}
		return (total/num);
	}else{
		for(int i=1; i<=num; i++){
			cout<<"How many points is "<< t<< " "<< i<< " worth?: ";
			cin>>yn;
			cout<<"How many points did you recieve?: ";
			cin>>score;
			total+=score/yn*100;
		}
		return (total/num);
	}

}

/*********************************************************************  
  ** Function:  recitation
  ** Description: Promps the user for each recitation catagories weight
   *then sends it to a function that calculates weighted averages.
  ** Parameters:  None
  ** Pre-Conditions: None
  ** Post-Conditions:  None
  ** Return: The user's grade in recitation as a double.
  *********************************************************************/ 
double recitation(){
	double recScore=0.0;
	int w;	
	cout<<"Quiz weight: ";
	cin>>w;
	if(w!=0){
		recScore+=weight_Average("Quiz",(w/100.0));
	}
	cout<<"Design weight: ";
	cin>>w;
	if(w!=0){
		recScore+=weight_Average("Design",(w/100.0));
	}
	cout<<"Critique weight: ";
	cin>>w;
	if(w!=0){
		recScore+=weight_Average("Critique",(w/100.0));
	}
	
	return recScore;	
}

/*********************************************************************  
  ** Function: weight_Average
  ** Description: Promts the user for their grade in a catagory, if they
   * do not know calls a function to calculate the grade, then calculates
   * the weighted version of the grade
  ** Parameters:  A string of the category being calculated for, and the weight 
   *  as a double
  ** Pre-Conditions: None
  ** Post-Conditions:  None
  ** Return: The weighted version of the users grade for a certain category as a double 
  *********************************************************************/ 
double weight_Average(string t, double w){
	double grade;
	cout<<"What is your overall grade in the "<< t << " catagory? Type -1 if you do not know: ";
	cin>>grade;
	if(grade==-1){
		if(t=="Recitation"){
			grade=recitation();
		}else{
			grade=LAT(t);
			
		}
	}

	return (grade*w);
}

/*********************************************************************  
  ** Function: ClassF
  ** Description: Takes user input of the weight of their different class catagories
   * then calls a function to calculate those catagory grades, adding them up to get
   * their overall class grade.
  ** Parameters:  None
  ** Pre-Conditions: None 
  ** Post-Conditions:  None
  ** Return: None
  *********************************************************************/ 
void classF(){
	double classScore=0.0;
	int w;
	cout<<"Lab weight: ";
	cin>>w;
	if(w!=0){
		classScore+=weight_Average("Lab",(w/100.0));
	}
	cout<<"Assignment weight: ";
	cin>>w;
	if(w!=0){
		classScore+=weight_Average("Assignment",(w/100.0));
	}
	cout<<"Test weight: ";
	cin>>w;
	if(w!=0){
		classScore+=weight_Average("Test",(w/100.0));
	}
	cout<<"Recitation weight: ";
	cin>>w;
	if(w!=0){
		classScore+=weight_Average("Recitation",(w/100.0));
	}

	cout<<"Your overall Class grade is "<<classScore<<endl;
}


