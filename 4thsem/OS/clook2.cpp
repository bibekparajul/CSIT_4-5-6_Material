#include<stdio.h>
#include<stdlib.h>
int main()
{
    int REQUEST[100],i,j,n,TotalHeadMovement=0,initial,size,move;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    printf("Enter the Requests sequence\n");
    for(i=0;i<n;i++)
     scanf("%d",&REQUEST[i]);
    printf("Enter initial head position\n");
    scanf("%d",&initial);
    printf("Enter total disk size\n");
    scanf("%d",&size);
    printf("Enter the head movement direction for high 1 and for low 0\n");
    scanf("%d",&move);
    
    for(i=0;i<n;i++)
    {
        for( j=0;j<n-i-1;j++)
        {
            if(REQUEST[j]>REQUEST[j+1])
            {
                int temp;
                temp=REQUEST[j];
                REQUEST[j]=REQUEST[j+1];
                REQUEST[j+1]=temp;
            }

        }
    }

    int index;
    for(i=0;i<n;i++)
    {
        if(initial<REQUEST[i])
        {
            index=i;
            break;
        }
    }
   
    //for high move
    if(move==1)
    {
        for(i=index;i<n;i++)
        {
            TotalHeadMovement=TotalHeadMovement+abs(REQUEST[i]-initial);
            initial=REQUEST[i];
        }
        
        for( i=0;i<index;i++)
        {
             TotalHeadMovement=TotalHeadMovement+abs(REQUEST[i]-initial);
             initial=REQUEST[i];
            
        }
    }
    //for low move
    else
    {
        for(i=index-1;i>=0;i--)
        {
            TotalHeadMovement=TotalHeadMovement+abs(REQUEST[i]-initial);
            initial=REQUEST[i];
        }
        
        for(i=n-1;i>=index;i--)
        {
             TotalHeadMovement=TotalHeadMovement+abs(REQUEST[i]-initial);
             initial=REQUEST[i];
            
        }
    }
    
    printf("Total head movement is %d",TotalHeadMovement);
    return 0;
}

