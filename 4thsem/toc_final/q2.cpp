#include<iostream>
#include<string.h>
using namespace std;

void substring2(char[],int,int);
int main()
{
    char input[100]; int nos ,posStart;

    cout<<"enter the string :"; 
	cin>>input;
    cout<<"enter the starting position :"; 
	cin>>posStart;
    cout<<"enter number of string :"; 
	cin>>nos;
    substring2(input,posStart,nos);
}

//Q2 make a function substring2(w,a,b),
//where w is a string input
//a is starting position
//b is the number of symbols
void substring2(char input[],int pos,int nos)
{
    if ((pos >0 && pos + nos >0) && (pos <= strlen(input) && pos + nos <= strlen(input)) )
    {
        cout<<"Substring is :";
        pos --;
		 if(nos<0)
		 {
		 
		 nos++;
		 }
		 else
		 
		 {
		 nos--;
		 
		 }
        if(pos<=(pos + nos)) 
		{ 
		for(int i = pos;i<=(pos + nos);i++ )
		{ 
		
		cout<<input[i];  
		
		
		} 
		
		
		}
        else if(pos>(pos + nos)){ for(int i = (pos + nos);i<=pos;i++ ){ cout<<input[i];  } }
        cout<<endl;
    }
    else
    { 
	
	cout<<"please enter correct index and string"<<endl; }
    
}
