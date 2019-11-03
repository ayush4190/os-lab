#include<stdio.h>
#include<stdlib.h>

int main()
{
	int arr[20],i,j,n,h,temp[20] , seek_count=0,min = 999,curr,t;
	printf("enter the sequence length \n");
	scanf("%d",&n);
	for(i =0 ;i<n ;i++)
	scanf("%d",&arr[i]);
	printf("enter the head \n");
	scanf("%d",&h);
	for(i=0;i<n;i++)
	{
	min = 999;
		for(j=0;j<n;j++)
		{
		temp[j]=abs(arr[j]-h);
		if(min> temp[j] && (arr[j] != -1))
		{
			min = temp[j];
			curr = arr[j];
			t = j;
		}
		}
		seek_count= seek_count + min;
		h= curr;
		arr[t] = -1;
		
		
	}
	printf("seek time=%d",seek_count);
	return 0;
	
}
