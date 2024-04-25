#include<iostream>
#include<string.h>
using namespace std;
bool DFA_with_101(char[]);
enum states{q0,q1,q2,q3_final,Rejected};
int main()
{
    int i;char input[100];

    cout<<"Enter string :";
    cin>>input;    
    if (DFA_with_101(input)) {
	cout<<"String is accepted"<<endl;
	}
    else{
	cout<<"String is rejected"<<endl;
	}


    return 0;
}

bool DFA_with_101(char w[])
{
    string input;int state = q0;
    for(int i = 0;i<strlen(w);i++)
    {
        input = w[i];
        if (input != "1" && input != "0"){cout<<"Please enter valid string"<<endl;state = Rejected;break;}
        else
        {
            if(state == q0 && input == "0") {state = q0;}
            else if(state == q0 && input == "1") {state = q1;} 
            else if(state == q1 && input == "0"){state = q2;}
            else if(state == q1 && input == "1"){state = q1;}
            else if(state == q2 && input == "0"){state = q0;}
            else if(state == q2 && input == "1"){state = q3_final;}
            else if(state == q3_final && input == "0"){state = q3_final;}
            else if(state == q3_final && input == "1"){state = q3_final;}
        }
    }

    if (state == q3_final){return true;}
    else {return false;}

}





