#include<iostream>
#include<string.h>
using namespace std;
bool NFA_endingwith_01(char[]);
enum states{q0,q1,q2_finish,Rejected};
int main()
{
    int i;
	char input[100];

 
    cout<<"Enter string :"; cin>>input;    
    if (NFA_endingwith_01(input))
	 {
	cout<<"String is accepted"<<endl
	;}
    else{cout<<"String is rejected"<<endl;}

    return 0;

}

bool NFA_endingwith_01(char w[])
{
    string input;int state = q0;
    
    for(int i = 0;i<strlen(w);i++)
    {
        input = w[i];
        if (input != "1" && input != "0"){cout<<"Please enter valid string"<<endl;state =Rejected;break;}
        else
        {
            if(state == q0 && input == "0") {state = q1;}
            else if(state == q1 && input == "1"){state = q2_finish;}
            else if(state == q2_finish && input == "0"){state = q1;}
            else if(state == q2_finish && input == "1"){state = q0;}
        }
    }
    if (state == q2_finish){return true;}else {return false;}
}





