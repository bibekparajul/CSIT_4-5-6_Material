#include<iostream>
#include<string.h>
using namespace std;
int NFA_with_001(char[]);
enum states{q0,q1,q2,q3_finish,Rejected};
int main()
{
    int i;char input[100]; 
 
    cout<<"Enter string :";
    cin>>input;    
    if (NFA_with_001(input)) {cout<<"String is accepted"<<endl;}
    else{cout<<"String is rejected"<<endl;}

    return 0;

}
int NFA_with_001(char w[])
{
    string check_value;int state = q0;
    for(int i = 0;i<strlen(w);i++)
    {
        check_value = w[i];
        if (check_value != "1" && check_value != "0"){cout<<"Please enter valid string"<<endl;state = Rejected;break;}
        else
        {
            if(state ==q0 && check_value == "0") {state = q1;}
            else if(state ==q1 && check_value == "0"){state = q2;}
            else if(state ==q1 && check_value == "1"){state = q0;}
            else if(state ==q2 && check_value == "1"){state = q3_finish;}
        }
    }
    if (state ==q3_finish){return true;} else {return false;}

}





