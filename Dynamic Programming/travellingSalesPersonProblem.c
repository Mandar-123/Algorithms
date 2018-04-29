#include <stdio.h>
int c[50][50],sv;
int g(int ver,int no,int n,int x[],int *pos)
{
    int i,temp,min=1000,temppos;
    if(no==0)
        return c[ver][sv-1];
    for(i=0;i<n;i++)
    {
        if(x[i]==0)
            continue;
        x[i]=0;
        temp=c[ver][i]+g(i,no-1,n,x,&temppos);
        if(temp<min)
        {
            min=temp;
            *pos=i;
        }
        x[i]=1;
    }
    return min;
}
void main()
{
    int i,ver,edg,pos,v1,v2,cost,s,x[50];
    printf("Enter number of nodes:");
    scanf("%d",&ver);
    printf("Enter number of edges:");
    scanf("%d",&edg);
    printf("Enter edge and cost: \n");
    for(i=0;i<edg;i++)
    {
        scanf("%d%d",&v1,&v2);
        scanf("%d",&c[v1-1][v2-1]);
    }
    for(i=0;i<ver;i++)
        x[i]=1;
    s=ver-1;
    printf("Enter starting Vertex: ");
    scanf("%d",&sv);
    pos=sv-1;
    printf("PATH:  %d - ",sv);
    while(s>=1)
    {
        x[pos]=0;
        cost=g(pos,s,ver,x,&pos);
        if(s==ver-1)
            i=cost;
        printf("%d - ",pos+1);
        s--;
    }
    printf("%d\n\nCOST= %d ",sv,i);
}

/*

OUTPUT:

Enter number of nodes:4
Enter number of edges:12
Enter edge and cost:
1 2 10
2 1 5
2 4 10
4 2 8
4 3 9
3 4 12
3 1 6
1 3 15
2 3 9
3 2 13
1 4 20
4 1 8
Enter starting Vertex: 1
PATH:  1 - 2 - 4 - 3 - 1

COST= 35
*/