
#include<bits/stdc++.h> 
using namespace std; 


void bestFit(int blockSize[], int m, int processSize[], int n) 
{ 
	
	int allocation[n] , internalfrag[m]; 

	
	memset(allocation, -1, sizeof(allocation)); 

	
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
			internalfrag[i] = blockSize[bestIdx] - processSize[i]; 
			blockSize[bestIdx] = 0;
		} 
	} 

	cout << "\nProcess No.\tProcess Size\tBlock no.\n"; 
	for (int i = 0; i < n; i++) 
	{ 
		cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t"; 
		if (allocation[i] != -1) 
			cout << allocation[i] + 1; 
		else
			cout << "Not Allocated"; 
		cout << endl; 
	} 
} 

// Driver code 
int main() 
{ 
	
	int i,p , blockSize[20],processSize[20] ,b;
	printf("enter the number of process \n");
	scanf("%d",&p);
	printf(" process size\n");
	for(i=0;i<p ; i++)
	{
	scanf("%d",&processSize[i]);
	}
	printf("enter the block  \n");
	scanf("%d",&b);
	printf("enter the block sizes \n");
	for(i =0 ;i<b ; i++)
	{
		scanf("%d",&blockSize[i]);
	}

	bestFit(blockSize, b, processSize, p); 

	return 0 ; 
} 
