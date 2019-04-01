#include<stdio.h>
#include<stdlib.h>
void main()
{
int tot,block,file,ch,i,count=0,j;
printf("Enter memory size in kB\n");
scanf("%d",&tot);
printf("Enter block size in kB\n");
scanf("%d",&block);
int n=tot/block;
int mem[n][2];
for(i=0;i<n;i++)
{
    mem[i][0]=-1;
    mem[i][1]=-1;
}
ch=1;
int f,found;
while(ch)
{
    printf("Enter choice 1.print alloted 2.allot file 3.exit\n");
    scanf("%d",&ch);    
    switch(ch)
    {    
        case 1:
            for(i=0;i<n;i++)
                if(mem[i][0]!=-1)
                    printf("file %d block %d stored in %d block in memory\n",mem[i][0],mem[i][1],i);            
            break;
        case 2:
            found=0;
            printf("Enter file length in blocks\n");
            scanf("%d",&f);
            printf("Enter starting point\n");
            scanf("%d",&i);
            for(j=i;j<i+f;j++)
            {
                if(j>=n)
                {
                    printf("Out of bounds\n");
                    found=1;
                    break;    
                }
                if(mem[j][0]!=-1)
                {
                    found=1;
                    printf("%d file %d block present\n",mem[j][0],mem[j][1]);
                    break;                
                }
            }    
            if(found==1)
            {
                printf("Invalid\n");    
            }                    
            if(found==0)
            {
                count++;
                for(j=i;j<i+f;j++)
                {
                    mem[j][0]=count;
                    mem[j][1]=j-i+1;
                }
            }
            break;
        case 3:
            ch=0;
            break;
        default:
            printf("Invalid choice\n");
    }
}
}


