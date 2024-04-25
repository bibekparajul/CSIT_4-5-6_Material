#include<iostream>
#include<string.h>
using namespace std;
int stack[100], top = -1;
void push_in_stack(int input){  if(top == 100-1){cout<<"overflow"<<endl;} else { top ++; stack[top]=input; }}
void pop_from_stack() {if(top == -1){cout<<"empty stack no popping"<<endl;} else{top --;}}
int Value_top_of_stack(){if(top == -1){}else{return stack[top];}}
bool equal_no_1_followed_by_equal_0(char[]);
enum state{q0_starting,q1,q2_final,Rejected};

int main()
{
    char input[100];
    cout<<"PDA of equal number 0 followed by equal 1"<<endl;
    cout<<"Enter string :"; cin>>input; 
    if(equal_no_1_followed_by_equal_0(input)){cout<<"string is accepted"<<endl;} 
    else{cout<<"string is rejected"<<endl;}
    return 0;
}

bool equal_no_1_followed_by_equal_0(char a[])
{
    int state = q0_starting,Value_check;
    for(int i = 0;i<strlen(a);i++)
    {   
        Value_check = a[i];
        if (Value_check != 49 && Value_check != 48){state = Rejected;break;}
        else
        {
            if(state == q0_starting && top == -1 && Value_check == 48){push_in_stack(Value_check);state=q0_starting;}
            else if(state == q0_starting && Value_check == 48 && Value_top_of_stack() == 48){push_in_stack(Value_check);state=q0_starting;}
            else if(state == q0_starting && Value_check == 49 && Value_top_of_stack() == 48){pop_from_stack();state=q1;}
            else if(state == q1 && Value_check == 49 && Value_top_of_stack() == 48){pop_from_stack();state=q1;}
            else{state = Rejected;}
        }  
    }
    if (top == -1 && state != Rejected){state = q2_final;}
    if(state == q2_final){return true;}else{return false;}
}








