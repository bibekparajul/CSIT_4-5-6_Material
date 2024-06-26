 
 //program for least recently uses page replacement algorithm..
 
 #include<iostream>
    using namespace std;
    int main()
    {
    int nopages, nofaults, page[20],i ,count=0;
    cout<<"\n Enter no of pages :"; 
    cin>> nopages;  //it will store the number of Pages
    cout<<"\n Enter the Reference String:";
    for(i=0;i< nopages;i++)
    {
    cout<<"\t"; 
    cin>>page[i];
    }   
    cout<<"\n\t Enter the Number of frames:"; 
    cin>> nofaults;
    int frame[nofaults],fcount[nofaults];
    for(i=0;i< nofaults;i++)
    {
    frame[i]=-1;
    fcount[i]=0; //keeps tracks og pages last used
    }
    i=0;
    while(i< nopages)
    {
    int j=0,flag=0;
    while(j< nofaults)
        {
            if(page[i]==frame[j])
				{  //it will check whether the page already exist
                                             //in frames or not
                flag=1;
                fcount[j]=i+1;
                }
                j++;
        }   
        j=0;  
        cout<<"\n";
        cout<<"\t"<<page[i]<<":";   
        if(flag==0)
        	{
            int min=0,k=0;
            while(k<nofaults-1) 
                { 
                    if(fcount[min]>fcount[k+1]) //It will calculate the page which is
                                                 //least recently used
                    min=k+1;
                    k++;
                }
                frame[min]=page[i]; 
                fcount[min]=i+1;  //Increasing the time it will count the total Page Fault
                count++;           
                while(j< nofaults)
                 {
                cout<<"\t"<<frame[j];
                j++;
                 }
                }
            i++; 
        }
        cout<<"\n";
        cout<<"\n\t Page Fault:"<<count;
        cout<<"\n\t Page Hit:"<<nopages-count;
        return 0;
    }


