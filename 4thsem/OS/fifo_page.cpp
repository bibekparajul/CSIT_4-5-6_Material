// FIFO page replacement algorithm
#include <stdio.h>
int main()
{
    int request[] = {1,2,3,4,1,1};
    int pgFaults = 0;               //initially pagefault is zero
    int frames = 3;
    int a, b, s, pages;
    printf("fifo page replacement\n");
    pages = sizeof(request)/sizeof(request[0]);     //sizeof int is 4 bytes(for 5 pages 20 bytes)
    printf("the total no of pages are %d\n", pages);

    printf("request\t\t\tframe1\t\t\tframe2\t\t\tframe3");
    int temp[frames];
    for(a = 0; a < frames; a++)
    {
        temp[a] = -1;
    }
    for(a = 0; a < pages; a++)
    {
        s = 0;
        for(b=0; b < frames; b++)
        {
            if(request[a] == temp[b])
            {
                s++;
                pgFaults--;
            }
        }
        pgFaults++;
        if((pgFaults <= frames) && (s == 0))
        {
            temp[a] = request[a];
        }
        else if(s == 0)
        {
            temp[(pgFaults - 1) % frames] = request[a];
        }
      
        printf("\n%d\t\t\t",request[a]);
        for(b=0; b < frames; b++)
        {
            if(temp[b] != -1){
			
                printf(" %d\t\t\t", temp[b]);
            }
            else
                printf(" * \t\t\t");
        }
    }

    printf("\nTotal number of page faults:\t%d\n", pgFaults);
    return 0;
}
