#include<stdio.h>

void makerevcycle(int a[],int n)
{
    int i,t;
    t=a[n-1];
    for(i=n-1;i>0;i--)
    {
        a[i]=a[i-1];
    }
    a[0]=t;
}

void makecycle(int a[],int n)
{
    int i,t;
    t=a[0];
    for(i=0;i<n;i++)
    {
        a[i]=a[i+1];
    }
    a[n-1]=t;
}

void cycle(int x[20][20],int lb,int m,int ub)
{
    int i,col=ub-m-1;
    int no_col=m-lb+1,curr=m+1,count;
    int a[10];
    for(i=0;i<ub-m;i++)
    {
        a[i]=curr++;
    }
    while(no_col!=0)
    {
        count=0;
        for(i=lb;i<=m;i++)
        {
            x[i][col]= a[count++];
        }
        makecycle(a,ub-m);
        no_col--;
        col++;
    }

}

void revcycle(int x[20][20],int lb,int m,int ub)
{
    int i,col=ub-m-1;
    int no_col=m-lb+1,curr=lb,count;
    int a[50];
    for(i=0;i<ub-m;i++)
    {
        a[i]=curr++;
    }
    while(no_col!=0)
    {
        count=0;
        for(i=m+1;i<=ub;i++)
        {
            x[i][col]=a[count++];
        }
        makerevcycle(a,ub-m);
        no_col--;
        col++;
    }

}

void tennis(int x[20][20], int lb,int ub)
{
    int m;
    if(lb==ub-1)
    {
        x[lb][0]=ub;
        x[ub][0]=lb;
        return;
    }
    m=(lb+ub)/2;
    tennis(x,lb,m);
    tennis(x,m+1,ub);
    cycle(x,lb,m,ub);
    revcycle(x,lb,m,ub);
}

void main()
{
    int n,x[20][20]={0},i,j;
    printf("Enter no.of teams:");
    scanf("%d",&n);
    tennis(x,0,n-1);
    for(i=1;i<=n-1;i++)
        printf("DAY %d | ",i);
    printf("\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            printf("%dvs%d  | ",i+1,x[i][j]+1);

        }
        printf("\n");
    }
}

/*
OUTPUT:

DAY 1 | DAY 2 | DAY 3 | DAY 4 | DAY 5 | DAY 6 | DAY 7 |
1vs2    | 1vs3   | 1vs4   | 1vs5    | 1vs6   | 1vs7    | 1vs8   |
2vs1    | 2vs4   | 2vs3   | 2vs6    | 2vs7   | 2vs8   | 2vs5    |
3vs4    | 3vs1   | 3vs2   | 3vs7    | 3vs8   | 3vs5   | 3vs6    |
4vs3    | 4vs2   | 4vs1   | 4vs8    | 4vs5   | 4vs6   | 4vs7    |
5vs6    | 5vs7   | 5vs8   | 5vs1    | 5vs4   | 5vs3   | 5vs2    |
6vs5    | 6vs8   | 6vs7   | 6vs2    | 6vs1   | 6vs4   | 6vs3    |
7vs8    | 7vs5   | 7vs6   | 7vs3    | 7vs2   | 7vs1   | 7vs4    |
8vs7    | 8vs6   | 8vs5   | 8vs4    | 8vs3   | 8vs2   | 8vs1    |

*/
