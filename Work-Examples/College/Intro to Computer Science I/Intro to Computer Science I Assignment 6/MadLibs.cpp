/****************************************************************************************************
 ** Program Filename: MadLibs.cpp
 ** Author: Stephanie Babb
 ** Date: 3/18/17
 ** Description: A version of MadLibs with 3 preloaded stories that is given a story number and file of filler words to create a complete story.
 ** Input: File of words
 ** Output:None
 ***************************************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>

using namespace std;

/********************************************************************************************
 ** Function: fill_array
 ** Desription: Sorts words from the given file into the correct arrays of word type
 ** Paremeters: array of singular nouns, array of verbs, array of adjectives, array of plural nouns, array of verbs ending in ing, number of singular nouns, number of verbs, number of adjectives, number of plural nouns, number of verbs ending in ing
 ** Pre-Conditions: A word file must be properly passed in to get the words from and the arrays must be created and passed properly
 ** Post-Conditions: The arrays are filled
 ** Return: None
 ********************************************************************************************/
void fill_arrays(char n[][30],char v[][30],char a[][30],char plural[][30], char ing[][30], int & nrow, int & vrow, int & arow,int & srow, int & irow){
	char temp [40];
	cin.getline(temp, 40);
	while(strlen(temp)!=0){
	
	   	if(temp[0]=='v'){
			if(temp[strlen(temp)-1]=='g'&&temp[strlen(temp)-2]=='n'&&temp[strlen(temp)-3]=='i'){
				for(int i=0;i<30;i++){	
		   	  		ing[irow][i]=temp[i+5];
			  	}
				irow++; //keeps track of # of verbs ending in ing
			}else{
				for(int i=0;i<30;i++){
		   			v[vrow][i]=temp[i+5];
				}
				vrow++; //keeps track of # of verbs
				}			
		}else if(temp[0]=='n'){
			if(temp[strlen(temp)-1]=='s'){
				for(int i=0; i<30;i++){
					plural[srow][i]=temp[i+5];	
				}
				srow++; //keeps track of # of plural nouns
			}else{
				for(int i=0;i<30;i++){
					n[nrow][i]=temp[i+5];
				}	
				nrow++; //keeps track of # of singular nouns
			}
		}else{
			for(int i=0;i<30;i++){
				a[arow][i]=temp[i+10];
			}
			arow++; //keeps track of number of adjectives
		}
		
		cin.getline(temp,40);
	}

}

/********************************************************************************************
 ** Function: story1
 ** Desription: Prints out a completed version of the first story
 ** Paremeters: Array of singular nouns, array of verbs, array of adjectives, array of plural nouns, array of verbs ending in ing, number of singular nouns, number of verbs, number of adjectives, number of plural nouns, number of verbs ending in ing 
 ** Pre-Conditions: A word file is provided that contains a minum of one of each word type and the words are correctly alocated into arrays that are passed properly to this function.
 ** Post-Conditions: None
 ** Return: None
 ********************************************************************************************/
void story1(char n[][30], char v[][30], char a[][30], char p[][30], char ing[][30], int nr, int vr, int ar, int sr, int ir){
	cout<<"Most doctors agree that bicycle "<<ing[rand()%ir]<<" is a/an "<<a[rand()%ar]<<" form of exercise. "<<ing[rand()%ir]<<" a bicycle endables you to develop your "<<n[rand()%nr]<<" muscles, as well as increase the rate of your "<< n[rand()%nr]<<" beat. More "<<n[rand()%nr]<<" around the world "<< v[rand()%vr]<<" bicycles than drive "<<p[rand()%sr]<<". No matter what kind of "<<n[rand()%nr]<<" you "<<v[rand()%vr]<<", always be sure to wear a/an "<<a[rand()%ar]<<" helmet. Make sure to have "<<a[rand()%ar]<<" reflectors too!"<<endl;
}

/********************************************************************************************
 ** Function: story2
 ** Desription: Prints out a completed version of the second story
 ** Paremeters: Array of singular nouns, array of verbs, array of adjectives,number of singular nouns, number of verbs, number of adjectives
 ** Pre-Conditions: A word file is provided that contains a minum of one of each required word type and the words are correctly alocated into arrays that are passed properly to this function.
 ** Post-Conditions: None
 ** Return: None
 ********************************************************************************************/
void story2(char n[][30],char v[][30], char a[][30],int nr, int vr, int ar){
	cout<<"Yesterday, "<<n[rand()%nr]<<" and I went to the park. On our way to the "<<a[rand()%ar]<<" park, we saw a "<<a[rand()%ar]<<" "<<n[rand()%nr]<<" on a bike. We also saw big, "<<a[rand()%ar]<<" balloons tied to a "<<n[rand()%nr]<<". Once we got to the "<<a[rand()%ar]<<" park, the sky turned "<<a[rand()%ar]<<". It started to "<<v[rand()%vr]<<" and "<<v[rand()%vr]<<". "<<n[rand()%nr]<<" and I "<<v[rand()%vr]<<" all the way home. Tommorrow we will try to go to the "<<a[rand()%ar]<<" park again and I hope it doesn't "<<v[rand()%vr]<<"."<<endl;
}

/********************************************************************************************
 ** Function: story3
 ** Desription: Prints out a completed version of the third story
 ** Paremeters: Array of singular nouns, array of verbs, array of adjectives, array of verbs ending in ing, number of singular nouns, number of verbs, number of adjectives, number of verbs ending in ing 
 ** Pre-Conditions: A word file is provided that contains a minum of one of each required word type and the words are correctly alocated into arrays that are passed properly to this function.
 ** Post-Conditions: None
 ** Return: None
 ********************************************************************************************/
void story3(char n[][30], char v[][30], char a[][30], char ing[][30], int nr, int vr, int ar, int ir){
	cout<<"Sping break 2017, oh how I have been waiting for you! Spring break is when you go to some "<<a[rand()%ar]<<" place to spend time with "<<n[rand()%nr]<<". Getting to "<<n[rand()%nr]<<" is going to take "<<a[rand()%ar]<<" hours. My favorite part of spring break is "<<ing[rand()%ir]<<" in the "<<n[rand()%nr]<<". During spring break, "<<n[rand()%nr]<<" and I plan to "<<v[rand()%vr]<<" all the way to "<<n[rand()%nr]<<". After spring break, I will be ready to return to "<<n[rand()%nr]<<" and "<<v[rand()%vr]<<" hard to finish "<<n[rand()%nr]<<". Thanks spring break 2017!"<<endl;
}
int main(int argc, char *argv[]){
   	//cout<<argc<<endl;
	srand(time(NULL));
	int nrow=0;
	int nsrow=0;
	int vrow=0;
	int vingrow=0;
	int arow=0;
   	char nouns[25][30];
	char plural[25][30];
	char verbs[25][30];
	char ing[25][30];
	char adj[25][30];
	if(argc!=2){
		cout<<"You've entered an improper number of arguments. Please try again."<<endl;
		return 0;
	}
	if(argv[1][0]=='1'||argv[1][0]=='2'||argv[1][0]=='3'){
		fill_arrays(nouns,verbs,adj,plural,ing,nrow,vrow,arow,nsrow,vingrow);
		if(argv[1][0]=='1'){
			story1(nouns,verbs,adj,plural,ing,nrow,vrow,arow,nsrow,vingrow);
		}else if(argv[1][0]=='2'){
			story2(nouns,verbs,adj,nrow,vrow,arow);
		}else{
			story3(nouns,verbs,adj,ing,nrow,vrow,arow,vingrow);
		}
	}else{
		cout<<"You've entered an invalid story choice. Please try again"<<endl;
		return 0;
	}

	return 0;
}
