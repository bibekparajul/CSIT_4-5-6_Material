#include<iostream>
#include<string.h>
using namespace std; 
void substring1(char[],int,int);
int main()
{
    char input[100]; 
	int posEnd ,posStart;
//    do
	
    cout<<"enter the string :"; 
	cin>>input;
    cout<<" starting position of the string :"; 
	cin>>posStart;
    cout<<"ending position of the string :";  
	cin>>posEnd;
    substring1(input,posStart,posEnd);
//    cout<<"do  you want to continue[y/n]"; 
//	cin>>choice;
    
//	while(choice != "n");
}

//Q1 make a function substring1(w,a,b),
//where w is a string input given by user
//a is the starting position for extracting substring 
//b is the ending position of the substring
void substring1(char input[],int startPosition,int endPosition)
{   
    if ((startPosition >0 && endPosition >0) && (startPosition <= strlen(input) && endPosition <= strlen(input)) )
    {
        cout<<"Substring is :";
		 startPosition --;
		 endPosition--;
        if(startPosition<=endPosition)
        { 
		for(int i =startPosition;i<=endPosition;i++ )
		{ 
		cout<<input[i];  
		} 
		}
        else if(startPosition>endPosition)
        { 
		for(int i = startPosition;i>=endPosition;i-- )
		{ cout<<input[i];
		  }
		   }
        cout<<endl;
    }
    else { 
	cout<<"error occured enter correct index and string"<<endl; 
	}
    
}




