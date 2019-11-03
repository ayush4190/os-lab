#include<stdio.h>
#include<stdlib.h>

int main()
{
int number_reffernces,i,number_frame;
int pos;
printf("Enter the no. of references\n");
scanf("%d",&number_reffernces);
int r[number_reffernces];
printf("Enter the no. of frames\n");
scanf("%d",&number_frame);
int frame[number_frame];
int min[number_frame];
int hits=0,faults=0;
for(i=0;i<number_frame;i++)
    frame[i]=-1;
pos=0;
int j,alloted;
printf("Enter reference sequence. \n");
for(i=0;i<number_reffernces;i++)
{
    
    scanf("%d",&r[i]);
}
for(i=0;i<number_reffernces;i++)
{
    alloted=0;
    for(j=0;j<number_frame;j++)
        if(frame[j]==r[i])
        {
            printf("%d found at %d \n",r[i],j+1);
            hits++;
            alloted=1;
            break;
        }
    for(j=0;j<number_frame;j++)
        if(frame[j]==-1&&alloted!=1)
        {
            printf("%d entered at %d\n",r[i],j+1);
            faults++;
            frame[j]=r[i];
            alloted=1;
            break;
        }
    if(alloted==0)
    {
        int k;
        for(j=0;j<number_frame;j++)
        {
            min[j]=9999;
            for(k=i;k<number_reffernces;k++)
                if(r[k]==frame[j])
                {
                    min[j]=k;
                    break;    
                }                
            if(min[j]==9999)
            {
                printf("%d not found %d at frame %d is replaced\n",r[i],frame[j],j+1);        
                frame[j]=r[i];
                alloted=1;    
                faults++;
                break;        
            }
        }
        if(alloted==0)
        {
            int m=-1,rep;    
            for(j=0;j<number_frame;j++)
            {
                if(min[j]>m)
                {
                    m=min[j];
                    rep=j;            
                }    
            }    
            printf("%d not found %d at frame %d is replaced\n",r[i],frame[rep],rep+1);        
            alloted=1;    
            frame[rep]=r[i];
            faults++;
        }    
    }
}
printf("Final frames:\n");
for(j=0;j<number_frame;j++)
    printf("frame %d has reference %d\n",j+1,frame[j]);
printf("Faults %d\nHits %d\n",faults,hits);
return 0;
}

