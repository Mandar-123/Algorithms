#include <stdio.h>
#include <math.h>
#include<string.h>
int x[50],n,count=1;
void display()
{
    printf("Solution %d :\n\n",count++);
    int i,j;
    char s[50][50];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            s[i][j]='#';
    for(i=1;i<=n;i++)
        s[i-1][x[i]-1]='Q';
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%c ",s[i][j]);
        printf("\n");
    }
    printf("\n\n");
}
void nextvalue(int k)
{
    int j,c=1;
    while(c==1)
    {
        c=0;
        x[k]=(x[k]+1)%(n+1);
        if(x[k]==0)
            break;
        for(j=1;j<k;j++)
            if(x[j]==x[k] || abs(x[j]-x[k])==abs(j-k))
                c=1;
    }
}



void nqueens(int k)
{
    while(1)
    {
        nextvalue(k);
        if(x[k]==0)
            break;
        if(k==n)
            display();
        else nqueens(k+1);
    }
}
void main()
{
    printf("Enter number of queens: ");
    scanf("%d",&n);
    nqueens(1);
}

/*

OUTPUT 1 :

Enter number of queens: 6
Solution 1 :

# Q # # # #
# # # Q # #
# # # # # Q
Q # # # # #
# # Q # # #
# # # # Q #


Solution 2 :

# # Q # # #
# # # # # Q
# Q # # # #
# # # # Q #
Q # # # # #
# # # Q # #






Solution 3 :

# # # Q # #
Q # # # # #
# # # # Q #
# Q # # # #
# # # # # Q
# # Q # # #


Solution 4 :

# # # # Q #
# # Q # # #
Q # # # # #
# # # # # Q
# # # Q # #
# Q # # # #

OUTPUT 2:

Enter number of queens: 4
Solution 1 :

# Q # #
# # # Q
Q # # #
# # Q #


Solution 2 :

# # Q #
Q # # #
# # # Q
# Q # #
*/