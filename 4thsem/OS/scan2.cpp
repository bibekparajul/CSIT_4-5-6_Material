#include<stdio.h>
#include<stdlib.h>
int main()
{
    int REQ[100],i,j,n,TotalMove=0,initial,size,move;
    printf("nter the no of request\n");
    scanf("%d",&n);
    printf("enter the Requests sequence\n");
    for(i=0;i<n;i++)
	{
	scanf("%d",&REQ[i]);
    }
    printf("Enter initial head position\n");
    scanf("%d",&initial);
    printf("enter the total disk size\n");
    scanf("%d",&size);
    printf("Enter the head movement direction 1 for higher 0 for lower\n");
    scanf("%d",&move);
    
    for(i=0;i<n;i++)                        //initially do the sorting
    {
        for(j=0;j<n-i-1;j++)
        {
            if(REQ[j]>REQ[j+1])
            {
                int temp;
                temp=REQ[j];
                REQ[j]=REQ[j+1];
                REQ[j+1]=temp;
            }

        }
    }

    int index;
    for(i=0;i<n;i++)
    {
        if(initial<REQ[i])
        {
            index=i;
            break;
        }
    }
   
    // if direction is towards high
    if(move==1)
    {
        for(i=index;i<n;i++)
        {
           TotalMove=TotalMove+abs(REQ[i]-initial);
            initial=REQ[i];
        } 
       TotalMove=TotalMove+abs(size-REQ[i-1]-1);  //movement for max size
        initial = size-1;
        for(i=index-1;i>=0;i--)
        {
            TotalMove=TotalMove+abs(REQ[i]-initial);
             initial=REQ[i];
            
        }
    }
    // if direction is towards low
    else
    {
        for(i=index-1;i>=0;i--)
        {
           TotalMove=TotalMove+abs(REQ[i]-initial);
            initial=REQ[i];
        } 
       TotalMove=TotalMove+abs(REQ[i+1]-0);  //movement for min size
        initial =0;
        for(i=index;i<n;i++)
        {
            TotalMove=TotalMove+abs(REQ[i]-initial);
             initial=REQ[i];
            
        }
    }
    
    printf("Total movement is %d",TotalMove);
    return 0;
}


