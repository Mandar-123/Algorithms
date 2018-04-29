#include <stdio.h>

int m,x[50],w[50],n,count=1;

void display()
{
    int i;
    printf("Solution %d   :  ",count++);
    for(i=1;i<=n;i++)
            printf("%3d",x[i]);
    printf("\n");
}

void sumofsub(int s,int k,int r)
{
    x[k]=1;
    if(s+w[k]==m)
        display();
    else if(s+w[k]+w[k+1]<=m)
            sumofsub(s+w[k],k+1,r-w[k]);
    if(s+r-w[k]>=m && s+w[k+1]<=m)
    {
        x[k]=0;
        sumofsub(s,k+1,r-w[k]);
    }
}

void main()
{
    int i,sum=0;
    printf("Enter no. of items: ");
    scanf("%d",&n);
    printf("Enter items: ");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
        sum+=w[i];
    }
    printf("Enter sum required: ");
    scanf("%d",&m);
    printf("weight vector:  ");
    for(i=1;i<=n;i++)
            printf("%3d",w[i]);
    printf("\n");
    sumofsub(0,1,sum);
}

/*

OUTPUT 1:

Enter no. of items: 4
Enter items: 3 6 7 10
Enter sum required: 16
weight vector:    3  6  7 10
Solution 1   :    1  1  1  0
Solution 2   :    0  1  0  1

Output 2:
Enter no. of items: 4
Enter items: 4 5 8 9
Enter sum required: 9
weight vector:    4  5  8  9
Solution 1   :    1  1  0  0
Solution 2   :    0  0  0  1
*/