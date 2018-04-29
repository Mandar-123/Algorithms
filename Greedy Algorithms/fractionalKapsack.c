#include <stdio.h>
#include <stdlib.h>
typedef struct item
{
    float profit,weight,amt;
    int no;
}item;
void sort(item a[],int n)
{
    int i,j;
    item t;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1;j++)
        {
            if((a[j].profit/a[j].weight)<(a[j+1].profit/a[j+1].weight))
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
}
void sortbyno(item a[],int n)
{
    int i,j;
    item t;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1;j++)
        {
            if(a[j].no>a[j+1].no)
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
}
void main()
{
    item a[50];
    int i,n;
    float cp=0,cw=0,M,p,w;
    printf("Enter no. of items: ");
    scanf("%d",&n);
    printf("Enter maximum sack capacity :");
    scanf("%f",&M);
    for(i=0;i<n;i++)
    {
        printf("Enter profit and weight of item %d :",i+1);
        scanf("%f %f",&p,&w);
        a[i].profit=p;
        a[i].weight=w;
        a[i].amt=0;
        a[i].no=i+1;
    }
    sort(a,n);
    for(i=0;i<n;i++)
    {
        if((cw+a[i].weight)<M)
        {
            a[i].amt=1;
            cp=cp+a[i].profit;
            cw=cw+a[i].weight;
        }
        else
        {
            a[i].amt=(M-cw)/a[i].weight;
            cp=cp+a[i].profit*((M-cw)/a[i].weight);
            cw=M;
            break;
        }
    }
    sortbyno(a,n);
    printf("\n  item no. |  weight | profit | amount to take\n");
    for(i=0;i<n;i++)
    {
    printf(" %8d  |%5.0f    | %5.0f  | %5.2f\n",a[i].no,a[i].weight,a[i].profit,a[i].amt);
    }
    printf("Total profit = %f",cp);
}

/*

OUTPUT:

Enter no. of items: 6
Enter maximum sack capacity :13
Enter profit and weight of item 1 :18 7
Enter profit and weight of item 2 :5 2
Enter profit and weight of item 3 :9 3
Enter profit and weight of item 4 :10 5
Enter profit and weight of item 5 :7 2
Enter profit and weight of item 6 :12 3

  item no. |  weight | profit | amount to take
        1       |    7         |    18    |  0.71
        2       |    2         |     5     |  0.00
        3       |    3         |     9     |  1.00
        4       |    5         |    10    |  0.00
        5       |    2         |     7     |  1.00
        6       |    3         |    12    |  1.00
Total profit = 40.857143
*/