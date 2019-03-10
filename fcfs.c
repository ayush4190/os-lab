#include<stdio.h>
int main()
{
  int at[20],bt[20],ct[20],tt =0 ,atat,awt,wt[20],tat[20],i,n,pid[20],j;
  printf("enter the total number of process \n");
  scanf("%d",&n);
  for(i =0 ;i< n ;i++)
  {
    printf("enter at and bt\n" );
    scanf("%d %d",&at[i],&bt[i] );
    pid[i]= i+1;
    tt = tt +bt[i];
  }
  //bubble sort
  int temp;
  for(i =0 ;i<n ;i++)
  {
    for(j =0 ; j<n-i-1;j++)
    {
      if(at[j]>at[j+1])
      {
        temp = at[j];
        at[j] =at[j+1];
        at[j+1]= temp;
        temp = bt[j];
        bt[j] =bt[j+1];
        bt[j+1]= temp;
        temp = pid[j];
        pid[j] =pid[j+1];
        pid[j+1]= temp;

      }
    }
  }
  // calculating ct ,tat , wt
int k=0;
atat = 0 ;
awt = 0;

  for(i =0 ;i< n ;i++)
  {
    ct[i] = bt[i]+k;
    k= ct[i];
    tat[i]= ct[i] -at[i];
    wt[i] = tat[i] - bt[i];
    atat = atat+ tat[i];
    awt = awt + wt[i];
  }
  printf("pid AT BT WT TAT \n" );
  for(i =0 ;i< n ;i++)
  {
    printf("%d\t\t%d\t\t%d\t\t%d\\t%d\n",pid[i],at[i],bt[i],wt[i],tat[i] );
  }
  //print gantt chart
  printf("%lf average wt \n",((1.0)*awt)/n );
  printf("%lf average tat\n",((1.0)*atat)/n );
}
