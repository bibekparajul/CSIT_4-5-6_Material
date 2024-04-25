#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int DFA_endingwith_01(char[]);
enum states{q0,q1,q2,Rejected};
int main()
{
    int i;
	char input[100];
    cout<<"Enter string :";
    cin>>input;    
    if (DFA_endingwith_01(input)) 
	{
	cout<<"String is accepted"<<endl; 
	}
    else{
	cout<<"String is rejected"<<endl;
	}
    return 0;

}

int DFA_endingwith_01(char w[])
{
    string input;int state = q0;
    for(int i = 0;i<strlen(w);i++)
    {
        input= w[i];
        if (input != "1" && input != "0"){cout<<"Please enter valid string"<<endl;state = Rejected;break;}
        else
        {
            if(state == q0 && input == "0") {state = q1;}
            else if(state == q0 && input == "1") {state = q0;} 
            else if(state == q1 && input== "0"){state = q1;}
            else if(state == q1 && input == "1"){state = q2;}
            else if(state == q2 && input == "0"){state = q1;}
            else if(state == q2 && input == "1"){state = q0;}
        }
    }

    if (state == q2){
	return true;
	}
    else {
	return false;
	}

}





