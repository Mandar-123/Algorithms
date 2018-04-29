#include<stdio.h>
#include<string.h>
#define max 10000
int s[50],tos=-1,x[50][50],f[50];

void display(int a[][50],int n,int t)
{
    int i,j;
    printf(" ");
    for(i=0;i<n;i++)
        printf("   %d",i+1);
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",i+1);
        for(j=0;j<n;j++)
            if(a[i][j]!=-1)
                printf("%3d ",a[i][j]+t);
            else printf("%3d ",a[i][j]);
        printf("\n");
    }
}

int min(int x,int y)
{
    if(x<y)
        return x;
    else return y;
}
void push(int ele)
{
    s[++tos]=ele;
}
int pop()
{
    return(s[tos--]);
}




void findpath(int d[][50],int source,int dest)
{
    while(dest!=-1)
    {
        push(dest);
        dest=d[source][dest];
    }
}

void path(int d[][50],int source,int dest)
{
    int p1,p2,count=0;
    findpath(d,source,dest);
    while(tos!=0)
    {
            p1=pop();
            p2=pop();
            if(x[p1][p2]==max)
            {
                findpath(d,p1,p2);
            }
            else
            {
                f[count++]=p1;
                push(p2);
            }
    }
    f[count++]=pop();
}

void main()
{
    int a[50][50],d[50][50],n,e,v1,v2,i,j,c,k,temp,ch=1;
    printf("Enter no. of nodes: ");
    scanf("%d",&n);
    printf("Enter no. of edges: ");
    scanf("%d",&e);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(i==j)
                x[i][j]=a[i][j]=0;
            else x[i][j]=a[i][j]=max;
            d[i][j]=-1;
        }
    printf("Enter the edge and their cost\n");
    for(i=0;i<e;i++)
    {
        scanf("%d%d%d",&v1,&v2,&c);
        x[v1-1][v2-1]=a[v1-1][v2-1]=c;
        d[v1-1][v2-1]=v1-1;
    }
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                temp=a[i][j];
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
                if(a[i][j]!=temp)
                    d[i][j]=k;
            }
    printf("A Matrix :\n\n");
    display(a,n,0);
    printf("\n");
    printf("D Matrix :\n\n");
    display(d,n,1);
    printf("\n");
    while(ch!=0)
    {
        i=0;
        memset(f,-1,sizeof(int)*50);
        printf("\nEnter source and destination: ");
        scanf("%d%d",&v1,&v2);
        path(d,v1-1,v2-1);
        printf("PATH:  ");
        while(f[i]!=-1)
        {
            printf("%d ",f[i]+1);
            i++;
        }
        printf("\n");
        printf("COST: %d\n",a[v1-1][v2-1]);
        printf("\nDO YOU WANT TO CONTINUE: 1->YES 0->NO :");
        scanf("%d",&ch);
    }
}

/*

OUTPUT:

Enter no. of nodes: 4
Enter no. of edges: 7
Enter the edge and their cost
1 2 20
2 1 7
4 2 2
3 2 7
3 4 3
1 3 8
3 1 15
A Matrix :

    1   2   3   4

1   0  13   8  11
2   7   0  15  18
3  12   5   0   3
4   9   2  17   0

D Matrix :

    1   2   3   4

1  -1   4   1   3
2   2  -1   1   3
3   4   4  -1   3
4   2   4   2  -1


Enter source and destination: 3 1
PATH:  3 4 2 1
COST: 12

DO YOU WANT TO CONTINUE: 1->YES 0->NO :1

Enter source and destination: 1 2
PATH:  1 3 4 2
COST: 13

DO YOU WANT TO CONTINUE: 1->YES 0->NO :1

Enter source and destination: 4 3
PATH:  4 2 1 3
COST: 17

DO YOU WANT TO CONTINUE: 1->YES 0->NO :0
*/