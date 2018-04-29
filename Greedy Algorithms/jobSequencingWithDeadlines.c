#include <stdio.h>
#include <stdlib.h>
typedef struct job
{
    int job_no;
    int profit;
    int deadline;
}job;
typedef struct schedule
{
    int job_no;
    int flag;
}schedule;
int getslot(schedule s[],int dl)
{
    int i;
    for(i=dl;i>=1;i--)
        if(s[i].flag==0)
            return i;
    return -1;
}
void sort(job x[],int n)
{
    int i,j;
    job temp;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1;j++)
        {
            if(x[j+1].profit>x[j].profit)
            {
                temp=x[j];
                x[j]=x[j+1];
                x[j+1]=temp;
            }
        }
}
void jobsequencing(job x[],int n,schedule s[],int k)
{
    int i,profit,avail;
    sort(x,n);
    profit=0;
    for(i=0;i<n;i++)
    {
        avail=getslot(s,x[i].deadline);
        if(avail==-1)
        {
            printf("\njob %d cannot be scheduled \n",x[i].job_no);
        }
        else
        {
            s[avail].job_no=x[i].job_no;
            s[avail].flag=1;
            profit+=x[i].profit;
        }
    }
    printf("slot  | job no. \n");
    for(i=1;i<=k;i++)
    {
        printf("%5d |%5d\n",i,s[i].job_no);
    }
    printf("\nPROFIT = %d ",profit);

}
void main()
{
    int i,n,k;
    job x[20];
    schedule s[20]={0};
    printf("Enter number of jobs: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter job(job_no profit deadline ):");
        scanf("%d %d %d",&x[i].job_no,&x[i].profit,&x[i].deadline);
    }
    printf("Enter number of slots: ");
    scanf("%d",&k);
    jobsequencing(x,n,s,k);
}
