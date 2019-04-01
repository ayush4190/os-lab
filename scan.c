#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct request
{
    int value;
    int isVisited;
};
void main()
{
int n,i,limit;
printf("Enter no. of requests\n");
scanf("%d",&n);
struct request req[n];
printf("Enter upper limit\n");
scanf("%d",&limit);
for(i=0;i<n;i++)
{
    printf("Enter request no. %d\n",i+1);
    scanf("%d",&req[i].value);
    req[i].isVisited=0;
}
int init,st=0,min,j,pos,ch;
printf("Enter the initial head value\n");
scanf("%d",&init);
printf("Enter 1.right 2. left\n");
scanf("%d",&ch);
printf("%d-> ",init);
if(ch==1)
{
    for(i=init;i<limit;i++)
    {
        for(j=0;j<n;j++)
        {
            if(req[j].value==i&&req[j].isVisited==0)        
            {
                st+=abs(req[j].value-init);
                init=req[j].value;
                req[j].isVisited=1;                
                printf("%d-> ",init);
            }    
        }
    }
    st+=limit-init;
    init=limit;
    printf("%d-> ",init);
    for(i=init;i>=0;i--)
    {
        for(j=0;j<n;j++)
        {
            if(req[j].value==i&&req[j].isVisited==0)        
            {
                st+=abs(req[j].value-init);
                init=req[j].value;
                req[j].isVisited=1;                
                printf("%d-> ",init);
            }    
        }
    }
}
else
{
    for(i=init;i>=0;i--)
    {
        for(j=0;j<n;j++)
        {
            if(req[j].value==i&&req[j].isVisited==0)        
            {
                st+=abs(req[j].value-init);
                init=req[j].value;
                req[j].isVisited=1;                
                printf("%d-> ",init);
            }    
        }
    }
    st+=init;
    init=0;
    printf("%d-> ",init);
    for(i=init;i<limit;i++)
    {
        for(j=0;j<n;j++)
        {
            if(req[j].value==i&&req[j].isVisited==0)        
            {
                st+=abs(req[j].value-init);
                init=req[j].value;
                req[j].isVisited=1;                
                printf("%d-> ",init);
            }    
        }
    }
}
printf("\n");
printf("Seek time is %d\n",st);
}

