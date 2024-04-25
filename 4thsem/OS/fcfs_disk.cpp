// FCFS disk scheduling algorithm

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int request[15],i,p,TotalHeadMoment=0,initial;
    printf("Enter the number of Requests\n");
    scanf("%d",&p);
    printf(" \nenter the requests sequence");
    for(i=0;i<p;i++)
	{
     scanf("%d",&request[i]);
	}	
    printf("Enter initial head position\n");
    scanf("%d",&initial);        //read write head at initial
    

    
    for(i=0;i<p;i++)
    {
        TotalHeadMoment=TotalHeadMoment+abs(request[i]-initial);
        initial=request[i];     //for next request it is inittial
    }
    
    printf("Total head moment is %d",TotalHeadMoment);
  return 0;
}
