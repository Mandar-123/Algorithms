#include <stdio.h>
#include <stdlib.h>
void merge(int x[],int lb,int m,int ub)
{
    int temp[50],i=lb,j=m+1,k=0;
    while(i<=m && j<=ub)
    {
        if(x[i]<x[j])
            temp[k++]=x[i++];
        else temp[k++]=x[j++];
    }
    while(i<=m)
        temp[k++]=x[i++];
    while(j<=ub)
        temp[k++]=x[j++];
    k=0;
    for(i=lb;i<=ub;i++)
        x[i]=temp[k++];
}
void mergesort(int x[],int lb,int ub)
{
    int m;
    if(lb<ub)
    {
        m=(lb+ub)/2;
        mergesort(x,lb,m);
        mergesort(x,m+1,ub);
        merge(x,lb,m,ub);
    }
}
int partition(int x[],int lb,int ub)
{
    int val=x[lb],down=lb+1,up=ub,t;
    while(down<=up)
    {
        while(down<=up && x[down]<=val)
            down++;
        while(x[up]>val)
            up--;
        if(down<up)
        {
            t=x[down];
            x[down]=x[up];
            x[up]=t;
        }
    }
    x[lb]=x[up];
    x[up]=val;
    return up;
}
void quicksort(int x[],int lb,int ub)
{
    int p;
    if(lb<ub)
    {
        p=partition(x,lb,ub);
        quicksort(x,lb,p-1);
        quicksort(x,p+1,ub);
    }
}
void accept(int x[],int n)
{
    int i;
        for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
}
void display(int x[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n");
}

void main()
{
    int n,a[50],ch;
    do
    {
        printf("Enter no. of elements: ");
        scanf("%d",&n);
        printf("Enter elements: ");
        accept(a,n);
        printf("ENTER CHOICE : 1.Merge SORT    2.Quick SORT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: mergesort(a,0,n-1);
                    printf("Sorted elements: ");
                    display(a,n);
                    break;
            case 2: quicksort(a,0,n-1);
                    printf("Sorted elements: ");
                    display(a,n);
                    break;
            default:printf("INVALID CHOICE\n");
        }
        printf("DO YOU WANT TO CONTINUE: 1.YES   2.NO\n");
        scanf("%d",&ch);
    }while(ch==1);
    printf("THANKYOU");
}


/*
OUTPUT:
Enter no. of elements: 7                                                                                                                                                                                                             
Enter elements: 16 11 9 10 1 19 2                                                                                                                                                                                                    
ENTER CHOICE : 1.Merge SORT    2.Quick SORT                                                                                                                                                                                          
1                                                                                                                                                                                                                                    
Sorted elements: 1 2 9 10 11 16 19                                                                                                                                                                                                   
DO YOU WANT TO CONTINUE: 1.YES   2.NO                                                                                                                                                                                                
1                                                                                                                                                                                                                                    
Enter no. of elements: 10                                                                                                                                                                                                            
Enter elements: 55 4 33 15 1 7 16 29 30 0                                                                                                                                                                                            
ENTER CHOICE : 1.Merge SORT    2.Quick SORT                                                                                                                                                                                          
2                                                                                                                                                                                                                                    
Sorted elements: 0 1 4 7 15 16 29 30 33 55                                                                                                                                                                                           DO YOU WANT TO CONTINUE: 1.YES   2.NO                                                                                                                                                                                                2  
THANKYOU 
*/