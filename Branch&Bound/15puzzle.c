#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

typedef struct node
{
    struct node* parent;
    int mat[4][4],x, y,cost,level;
}node;

node* q[ 100000];
int f=0,r=-1;

int isempty()
{
	return(f==r+1);
}

void insert(node *p)
{
		q[++r]=p;
}

node* delete1()
{
	int i,pos=r;
	node *m,*z;
	m=q[r];
	for(i=r-1;i>=f;i--)
		if((q[i]->cost)<(m->cost))
		 {
			m=q[i];
		 	pos=i;
		 }
    z=q[pos];
	for(i=pos;i<r;i++)
		q[i]=q[i+1];
	r--;
	return z;
}

void copymatrix(int a[][4],int b[][4])
{
    int i,j;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            a[i][j]=b[i][j];
}

void printMatrix(int mat[][4])
{
    int i,j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%3d ", mat[i][j]);
        printf("\n");
    }
}
void swapnum(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

node* create(int mat[][4], int x, int y, int newX,int newY, int lev, node* par)
{
    node* p;
    p=(node *)malloc(sizeof(node));
    p->parent = par;
    copymatrix(p->mat,mat);
    swapnum(&(p->mat[x][y]),&(p->mat[newX][newY]));
    p->cost=INT_MAX;
    p->level=lev;
    p->x=newX;
    p->y=newY;
    return p;
}

int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };

int isSafe(int x, int y)
{
    return (x >= 0 && x < 4 && y >= 0 && y < 4);
}
int calculateCost(int initialmat[][4], int finalmat[][4],int lvl)
{
    int count = 0,i,j;
    for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++)
        if (initialmat[i][j] && (initialmat[i][j] != finalmat[i][j]))
           count++;
    return count+lvl;
}

void printPath(node* p)
{
    if (p == NULL)
        return;
    printPath(p->parent);
    printMatrix(p->mat);
    printf("\n");
}

void solve(int initialmat[][4], int x, int y,int finalmat[][4])
{
    int i;
    node *root,*child;
    root = create(initialmat, x, y, x, y, 0, NULL);
    root->cost = calculateCost(initialmat, finalmat,root->level);
    insert(root);
    while (!isempty())
    {
        node* min = delete1();
        if (min->cost-min->level == 0)
        {
            printf("\nSTEPS-->\n\n");
            printPath(min);
            return;
        }
        for (i = 0; i < 4; i++)
        {
            if (isSafe(min->x + row[i], min->y + col[i]))
            {
                child = create(min->mat, min->x,min->y, min->x + row[i],min->y + col[i],min->level + 1, min);
                child->cost = calculateCost(child->mat, finalmat,child->level);
                insert(child);
            }
        }
    }
}
int isSolavabe(int mat[][4],int xpos,int ypos)
{
    int x,less=0,i,j,m,n,curr;
    if((xpos+ypos)%2==0)
        x=0;
    else x=1;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        {
            curr=mat[i][j];
            if(curr==0)
                continue;
            for(m=i;m<4;m++)
                for(n=0;n<4;n++)
                {
                    if(m==i && n<=j)
                        continue;
                    else if(mat[m][n]<curr && mat[m][n]!=0)
                        less++;
                }
        }
    return((less+x+1)%2);
}

void main()
{
    int initialmat[4][4],x,y,i,j;
    int finalmat[4][4] ={{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12},{13, 14, 15, 0}};
    printf("Enter initial puzzle(Enter Space as 0):\n\n");
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        {
            scanf("%d",&initialmat[i][j]);
            if(initialmat[i][j]==0)
            {
                x=i;
                y=j;
            }
        }
    if(isSolavabe(initialmat,x,y))
        solve(initialmat, x, y, finalmat);
    else printf("\nPuzzle is not Solvable");
}


/*


OUTPUT:


Enter initial puzzle(Enter Space as 0):

2 10 3 4
1 0 6 8
5 14 7 11
9 13 15 12.

STEPS-->

  2  10   3   4
  1   0   6   8
  5  14   7  11
  9  13  15  12

  2   0   3   4
  1  10   6   8
  5  14   7  11
  9  13  15  12

  0   2   3   4
  1  10   6   8
  5  14   7  11
  9  13  15  12

  1   2   3   4
  0  10   6   8
  5  14   7  11
  9  13  15  12

  1   2   3   4
  5  10   6   8
  0  14   7  11
  9  13  15  12

  1   2   3   4
  5  10   6   8
  9  14   7  11
  0  13  15  12

  1   2   3   4
  5  10   6   8
  9  14   7  11
 13   0  15  12

  1   2   3   4
  5  10   6   8
  9   0   7  11
 13  14  15  12

  1   2   3   4
  5   0   6   8
  9  10   7  11
 13  14  15  12

  1   2   3   4
  5   6   0   8
  9  10   7  11
 13  14  15  12

  1   2   3   4
  5   6   7   8
  9  10   0  11
 13  14  15  12

  1   2   3   4
  5   6   7   8
  9  10  11   0
 13  14  15  12

  1   2   3   4
  5   6   7   8
  9  10  11  12
 13  14  15   0
*/