#include<iostream>
using namespace std;
int main()
{
    int partition,pocessNumber,i,j;
        cout<<"Enter number of partition: ";
		cin>>partition;
        cout<<"enter the no of process to be allocated: ";
		cin>>pocessNumber;
        int processes[pocessNumber];
		int holes[partition];
        cout<<"Enter The size of partitions: \n";
        for(i = 0 ; i < partition ; i++)
		{  
			cout<<i+1<<": ";
			cin>>holes[i]; 
		}
        cout<<"enter size of process: \n";
        for(i = 0 ; i < pocessNumber ; i++)
		{
		  cout<<i+1<<": ";
		  cin>>processes[i];
	    }
        for(i = 0 ; i < pocessNumber ; i++)
        {  
            for(j = 0 ; j < partition ; j++)
            {  
                if(processes[i] <= holes[j])
                {
                    cout<<"the process "<<i+1<<" fits in partition "<<j+1<<endl;
                    holes[j] = holes[j] - processes[i];
                    break;
                }  
            }          
        }
}

