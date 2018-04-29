#include <stdio.h>
#include <stdlib.h>
typedef struct temp
{
    int x,y,c;
}temp;
void sort(temp arr[],int edg)
{
    int i,j;
    temp t;
    for(i=0;i<edg-1;i++)
        for(j=0;j<edg-1-i;j++)
        {
            if(arr[j].c>arr[j+1].c)
            {
                t=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=t;
            }
        }
}
void MAKE_SET(int SET[20][20])
{
    int i;
    for(i=0;i<20;i++)
        SET[i][i]=1;
}
void UNION(int SET[20][20],int ver,int x,int y)
{
    int i,j;
    for(i=0;i<ver;i++)
    {
        if(SET[x][i]==1)
            SET[y][i]=1;
        if(SET[y][i]==1)
            SET[x][i]=1;
    }
    for(i=0;i<ver;i++)
        if(SET[x][i]==1)
            for(j=0;j<ver;j++)
                SET[i][j]=SET[x][j];
}

void main()
{
    temp arr[20],t,solution[20];
    int i,j,ver,edg,e1,e2,cost,SET[20][20]={0},finalcost=0,k;
    printf("Enter no. of vertices and edges: ");
    scanf("%d%d",&ver,&edg);
    for(i=0;i<edg;i++)
    {
        printf("Enter edge %d and cost(e1 e2 cost): ",i+1);
        scanf("%d %d %d",&e1,&e2,&cost);
        arr[i].x=e1-1;
        arr[i].y=e2-1;
        arr[i].c=cost;
    }
    MAKE_SET(SET);
    sort(arr,edg);
    k=0;
    for(i=0;i<edg;i++)
    {
        if(SET[arr[i].x][arr[i].y]!=1)
        {
            solution[k++]=arr[i];
            UNION(SET,ver,arr[i].x,arr[i].y);
        }
    }
    printf("\n***SOLUTION***\nEDGE  COST");
    for(i=0;i<k;i++)
    {
        printf("\n%d %d %5d",solution[i].x+1,solution[i].y+1,solution[i].c);
        finalcost+=solution[i].c;
    }
    printf("\n\nFINAL COST= %d",finalcost);
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

***SOLUTION***
EDGE  COST
2 6    10
2 4    20
5 6    30
1 2    50
1 3    70

FINAL COST= 180



OUTPUT 2:

Enter no. of vertices and edges: 5 6
Enter edge 1 and cost(e1 e2 cost): 1 2 50
Enter edge 2 and cost(e1 e2 cost): 1 4 15
Enter edge 3 and cost(e1 e2 cost): 1 5 30
Enter edge 4 and cost(e1 e2 cost): 2 3 10
Enter edge 5 and cost(e1 e2 cost): 2 4 60
Enter edge 6 and cost(e1 e2 cost): 3 5 20

***SOLUTION***
EDGE  COST
2 3    10
1 4    15
3 5    20
1 5    30

FINAL COST= 75
*/