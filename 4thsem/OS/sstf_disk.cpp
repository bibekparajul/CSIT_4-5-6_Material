#include<stdio.h>
#include<stdlib.h>
int main()
{
    int request[100],i,p,TotalHeadMoment=0,initial,count=0;
    printf("Enter the number of Requests\n");
    scanf("%d",&p);
    printf("\nEnter the Requests sequence");
    for(i=0;i<p;i++)
    	{
     scanf("%d",&request[i]);
    	}
    printf("\nEnter initial head position");
    scanf("%d",&initial);
    
    while(count!=p)
    {
        int val=1000,d,index;
        for(i=0;i<p;i++)
        {
           d=abs(request[i]-initial);    // calculating the minimum distance 
           if(val>d)
           {
               val=d;
               index=i;
           }
           
        }
        TotalHeadMoment=TotalHeadMoment+val;
        initial=request[index];
        // 1000 is for max
        // you can use any number
        request[index]=1000;
        count++;
    }
    
    printf("Total head movement is %d",TotalHeadMoment);
    return 0;
}
