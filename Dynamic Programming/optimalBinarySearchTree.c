#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
typedef struct wcr
{
    int we,co,r;
}wcr;
int p[50],q[50];
int w(int i,int j)
{
    if(i==j)
        return(q[i]);
    else return(p[j]+q[j]+w(i,j-1));
}
int c(int i,int j,int *pos)
{
    int k,min,temp;
    int temppos;
    min=INT_MAX;
    if(i==j)
    {
        *pos=0;
        return 0;
    }
    for(k=i+1;k<=j;k++)
    {
        temp=c(i,k-1,&temppos)+c(k,j,&temppos);
        if(temp<min)
        {
            min=temp;
            *pos=k;
        }
    }
    return(w(i,j)+min);
}
void preorder(wcr table[][50],int x,int y)
{
    int i=y-x,j=x;
    if(x==y)
            return;
    printf("%d ",table[i][j].r);
    preorder(table,x,table[i][j].r-1);
    preorder(table,table[i][j].r,y);
}
void postorder(wcr table[][50],int x,int y)
{
    int i=y-x,j=x;
    if(x==y)
            return;
    postorder(table,x,table[i][j].r-1);
    postorder(table,table[i][j].r,y);
    printf("%d ",table[i][j].r);
}
void inorder(wcr table[][50],int x,int y)
{
    int i=y-x,j=x;
    if(x==y)
            return;
    inorder(table,x,table[i][j].r-1);
    printf("%d ",table[i][j].r);
    inorder(table,table[i][j].r,y);
}
void main()
{
    int n,i,j,d,pos;
    wcr table[50][50]={0};
    printf("Enter number of identifiers: ");
    scanf("%d",&n);
    printf("Enter probability of identifiers(1 to %d): \n",n);
    for(i=1;i<=n;i++)
        scanf("%d",&p[i]);
    printf("Enter probability of Equivalence classes(0 to %d): \n",n);
    for(i=0;i<=n;i++)
        scanf("%d",&q[i]);
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
        {
            if(j+i<=n)
            {
                table[i][j].we=w(j,j+i);
                table[i][j].co=c(j,j+i,&pos);
                table[i][j].r=pos;
            }
        }
    printf("\nInorder: ");
    inorder(table,0,n);
    printf("\nPreorder: ");
    preorder(table,0,n);
    printf("\nPostorder: ");
    postorder(table,0,n);
    printf("\n\nCOST OF OBST= %d ",c(0,n,&pos));
}

/*

OUTPUT 1 :

Enter number of identifiers: 4
Enter probability of identifiers(1 to 4):
3 3 1 1
Enter probability of Equivalence classes(0 to 4):
2 3 1 1 1

Inorder: 1 2 3 4
Preorder: 2 1 3 4
Postorder: 1 4 3 2

COST OF OBST= 32

OUTPUT 2:

Enter number of identifiers: 9
Enter probability of identifiers(1 to 9):
3 2 1 5 1 6 2 3 4
Enter probability of Equivalence classes(0 to 9):
4 2 3 1 2 5 4 1 2 1

Inorder: 1 2 3 4 5 6 7 8 9
Preorder: 6 4 1 2 3 5 8 7 9
Postorder: 3 2 1 5 4 7 9 8 6

COST OF OBST= 150
*/