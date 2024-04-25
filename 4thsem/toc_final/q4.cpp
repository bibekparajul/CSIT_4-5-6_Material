#include<iostream>
#include<string.h>
using namespace std;
void suffix2(char[],int);
void prefix2(char[],int);
int main()
{
    char input[100];int removeSuffix,removePrefix;

    cout<<"Enter the string: "; cin>>input;
    cout<<"Enter suffix removal value: "; cin>>removeSuffix;
    cout<<"Enter prefix removal value: "; cin>>removePrefix;
    suffix2(input, removeSuffix);
    prefix2(input,removePrefix);
    return 0;
}
void prefix2(char w[],int n)
{   
    if(n>=0 && n <strlen(w))
    {
        cout<<"The  remaining string (prefix) are: ";
        for(int i = n; i<strlen(w);i++) { cout<<w[i]; }
        cout<<endl;
    }else
	{
	cout<<"error"<<endl;
	}
}
void suffix2(char w[],int n)
{
    if(n>=0 && n <strlen(w))
    {
        cout<<"The remaining string (suffix) are: ";
        for(int i = 0; i<strlen(w) - n;i++){ cout<<w[i]; }
        cout<<endl;
    }else{cout<<"error"<<endl;}
}
