#include <stdio.h>
#include <math.h>
#include<string.h>
int x[50],adj[50][50],m,n,count=1;
void display()
{
    printf("Solution %d :\n\n",count++);
    int i;
    printf("node :  ");
    for(i=1;i<=n;i++)
        printf("%d ",i);
    printf("\n");
    printf("color:  ");
    for(i=1;i<=n;i++)
        printf("%d ",x[i]);
    printf("\n\n");
}
void nextvalue(int k)
{
    int j,c=1;
    while(c==1)
    {
        c=0;
        x[k]=(x[k]+1)%(m+1);
        if(x[k]==0)
            return;
        for(j=1;j<k;j++)
            if(x[j]==x[k] && adj[j][k]==1)
                c=1;
    }
}
void color_graph(int k)
{
    while(1)
    {
        nextvalue(k);
        if(x[k]==0)
            break;
        if(k==n)
            display();
        else color_graph(k+1);
    }
}
void main()
{
    int i,edg,u,v;
    printf("Enter number of nodes : ");
    scanf("%d",&n);
    printf("Enter number of edges: ");
    scanf("%d",&edg);
    printf("Enter Edges\n");
    for(i=0;i<edg;i++)
    {
        scanf("%d %d",&u,&v);
        adj[u][v]=1;
        adj[v][u]=1;
    }
    printf("Enter number of colors: ");
    scanf("%d",&m);
    color_graph(1);
}




/*

OUTPUT:

Enter number of nodes : 4
Enter number of edges: 5
Enter Edges
1 2
2 4
4 3
1 3
1 4
Enter number of colors: 3
Solution 1 :

node :  1 2 3 4
color:  1 2 2 3

Solution 2 :

node :  1 2 3 4
color:  1 3 3 2

Solution 3 :

node :  1 2 3 4
color:  2 1 1 3

Solution 4 :

node :  1 2 3 4
color:  2 3 3 1

Solution 5 :

node :  1 2 3 4
color:  3 1 1 2

Solution 6 :

node :  1 2 3 4
color:  3 2 2 1
*/