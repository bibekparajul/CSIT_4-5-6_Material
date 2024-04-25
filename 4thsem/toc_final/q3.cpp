#include<iostream>
#include<string.h>
using namespace std;
void suffix(char[]);
void prefix(char[]);
int main()
{
    char input[100];
	
    cout<<"Enter the string: "; 
	cin>>input;
    prefix(input); 
	suffix(input);
    
    return 0;
}
void prefix(char a[])
{
    cout<<"The possible prefix are: "<<endl;
    for(int i = 0; i<strlen(a);i++)
    {
        for(int j = 0;j<=i;j++)
		{
		cout<<a[j];
		 }
        cout<<endl;
    }
}
void suffix(char a[])
{
    cout<<"The possible suffix are: "<<endl;
    for(int i = strlen(a)-1; i>=0;i--)
    { 
        for(int j = i;j<strlen(a);j++){cout<<a[j]; } 
        cout<<endl;  
    }
}
