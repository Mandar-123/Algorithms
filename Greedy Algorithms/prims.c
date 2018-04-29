#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
int EXTRACT_MIN(int ver,int q[],int d[])
{
    int i,min=INT_MAX,pos;
    for(i=0;i<ver;i++)
    {
        if(q[i]!=1 && d[i]<min)
        {
            min=d[i];
            pos=i;
        }
    }
    q[pos]=1;
    return pos;
}
int isnotempty(int ver,int q[])
{
    int i,ne=0;
    for(i=0;i<ver;i++)
        if(q[i]==0)
            ne=1;
    return ne;
}
void main()
{
    int i,j,ver,edg,weight[20][20],d[20],pi[20],u,v,q[20]={0},e1,e2,cost,r;
    printf("Enter no. of vertices and edges: ");
    scanf("%d%d",&ver,&edg);
    memset(weight,-1, sizeof(int)*20*20);
    for(i=0;i<edg;i++)
    {
        printf("Enter edge %d and cost(e1 e2 cost): ",i+1);
        scanf("%d %d %d",&e1,&e2,&cost);
        weight[e1-1][e2-1]=cost;
        weight[e2-1][e1-1]=cost;
    }
    for(i=0;i<ver;i++)
    {
        d[i]=INT_MAX;
        pi[i]=-1;
    }
    printf("Enter starting vertex: ");
    scanf("%d",&r);
    d[r-1]=0;
    while(isnotempty(ver,q))
    {
        u=EXTRACT_MIN(ver,q,d);
        for(v=0;v<ver;v++)
        {
            if(weight[u][v]!=-1 && q[v]==0)
            {
                if(weight[u][v]<d[v])
                {
                    d[v]=weight[u][v];
                    pi[v]=u;
                }
            }
        }
    }
    cost=0;
    printf("\n*********Solution**********\n");
    for(i=0;i<ver;i++)
    {
        if(pi[i]!=-1)
        {
            printf("(%d,%d)\n",i+1,pi[i]+1);
            cost = cost+d[i];
        }
    }
    printf("\nCost= %d",cost);
}





/*


OUTPUT 1:

Enter no. of vertices and edges: 6 8
Enter edge 1 and cost(e1 e2 cost): 1 2 50
Enter edge 2 and cost(e1 e2 cost): 1 3 70
Enter edge 3 and cost(e1 e2 cost): 1 5 60
Enter edge 4 and cost(e1 e2 cost): 2 4 20
Enter edge 5 and cost(e1 e2 cost): 2 6 10
Enter edge 6 and cost(e1 e2 cost): 3 4 80
Enter edge 7 and cost(e1 e2 cost): 4 5 40
Enter edge 8 and cost(e1 e2 cost): 5 6 30
Enter starting vertex: 3

*********Solution**********
(1,3)
(2,1)
(4,2)
(5,6)
(6,2)

Cost= 180

OUTPUT 2 :
Enter no. of vertices and edges: 5 6
Enter edge 1 and cost(e1 e2 cost): 1 2 5
Enter edge 2 and cost(e1 e2 cost): 1 4 15
Enter edge 3 and cost(e1 e2 cost): 1 5 30
Enter edge 4 and cost(e1 e2 cost): 2 3 10
Enter edge 5 and cost(e1 e2 cost): 2 4 60
Enter edge 6 and cost(e1 e2 cost): 3 5 20
Enter starting vertex: 1

*********Solution**********
(2,1)
(3,2)
(4,1)
(5,3)

Cost= 50
*/