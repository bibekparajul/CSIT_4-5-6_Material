#include<iostream>
#include<string.h>
using namespace std;

int stack[100], top = -1;
void push_in_stack(int input){  if(top == 100-1){cout<<"overflow"<<endl;} else { top ++; stack[top]=input; }}
void pop_from_stack() {if(top == -1){cout<<"empmty stack no pop"<<endl;} else{top --;}}
int Value_top_of_stack(){if(top == -1){}else{return stack[top];}}
bool equal_1_and_0(char[]);
enum state{q0_starting,q1_final,Rejected};

int main()
{
    char input[100];
    
    cout<<"PDA for accepting or rejecting the equal number of 0 and 1"<<endl;
    cout<<"Enter string :";
    cin>>input; 
    if(equal_1_and_0(input)){cout<<"string is accepted"<<endl;}
    else{cout<<"string is rejected"<<endl;}

    
    return 0;
}

bool equal_1_and_0(char a[])
{
    int state = q0_starting,Value_check;
    for(int i = 0;i<strlen(a);i++)
    {   
        Value_check = a[i];
        if (Value_check != 49 && Value_check != 48){state = Rejected;break;}
        else
        {
            if(state == q0_starting && top == -1){push_in_stack(Value_check);state = q0_starting;}
            else if(state == q0_starting && (Value_check == Value_top_of_stack())){push_in_stack(Value_check);state = q0_starting;}
            else if(state == q0_starting && (Value_check != Value_top_of_stack()) && top >-1){pop_from_stack();state = q0_starting;}
            else{state = Rejected;}
        }  
    }
    if (top == -1 && state != Rejected){state = q1_final;}
    if(state == q1_final){return true;}else{return false;}

}








