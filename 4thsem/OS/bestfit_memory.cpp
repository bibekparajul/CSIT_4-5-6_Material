//bestfit algorithm

#include<bits/stdc++.h>
using namespace std;

// Function to allocate memory to blocks as per Best fit algorithm
void bestFit(int blockSize[], int m, int processSize[], int n)
{
    // Stores block id of the block allocated to a process
    int allocation[n];

    // Initially no block is assigned to any process
    memset(allocation, -1, sizeof(allocation));

    // pick each process and find suitable blocks according to its size ad assign to it
    for (int i=0; i<n; i++)
    {
        // Find the best fit block for current process
        int bestIdx = -1;
        for (int j=0; j<m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
            }
        }

        if (bestIdx != -1)
        {
            // allocate block j to p[i] process
            allocation[i] = bestIdx;

            // Reduce available memory in this block.
            blockSize[bestIdx] -= processSize[i];

        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << "   " << i+1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main()
{
	int m,n, processSize[20],blockSize[20],i;
	cout<<"Enter the no of block\n";
	cin>>m;
	cout<<"Enter the size of each blocks\n";
	for(i=0;i<m;i++)
	{
		cin>>blockSize[i];
	}
	cout<<"Enter the no. of process\n";
	cin>>n;
	cout<<"Enter the size of each process\n";
	for(i=0;i<n;i++)
	{
		cin>>processSize[i];
	}
    bestFit(blockSize, m, processSize, n);

    return 0 ;
}

