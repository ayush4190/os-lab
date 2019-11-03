#include<stdlib.h>
#include<stdio.h>
int main()
{
int f[50],p,i,j,k,a,st,len,n,c,*s[50];
for(i=0;i<50;i++)
{f[i]=0;s[50];}
printf("Enter how many blocks that are already allocated");
scanf("%d",&p);
printf("\nEnter the blocks no.s that are already allocated");
for(i=0;i<p;i++){
scanf("%d",&a);
f[a]=1;
s[a] = &f[a];
}
X:
printf("Enter the starting index block & length");
scanf("%d%d",&st,&len);
k=len;
for(j=st;j<(k+st);j++)
{
if(f[j]==0)
{
i=0;
f[j]=1;
s[j]=&f[j];

printf("\n%d->%d",j,f[j]);
}
else
{
printf("\n %d->file is already allocated %p",j,s[j]);
k++;
}
}
printf("\n If u want to enter one more file? (yes-1/no-0)");
scanf("%d",&c);
if(c==1)
goto X;
else
exit(0);
return 0;

}
