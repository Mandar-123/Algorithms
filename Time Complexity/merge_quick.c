#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void merge(int x[],int lb,int m,int ub)
{
    int temp[100000],i=lb,j=m+1,k=0;
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
void main()
{
     int i;
     clock_t start,end;
     FILE *fp;
     char str[50];
     long int n;
     int x[100000],a[100000];
     printf("Enter name of the file: ");
     scanf("%s",str);
     fp=fopen(str,"w");
     printf("Enter no. of integers: ");
     scanf("%li",&n);
     for(i=0;i<n;i++)
      fprintf(fp,"%d\n",(rand()%10000));
     fp=fopen(str,"r");
     i=0;
     while(1)
     {
      if(feof(fp)!=0)
        break;
      fscanf(fp,"%d",&x[i++]);
     }
      i=0;
     while(1)
     {
      if(feof(fp)!=0)
        break;
      fscanf(fp,"%d",&a[i++]);
     }
     start=clock();
     quicksort(x,0,n-1);
     end=clock();
     printf("%li unsorted integers quick sort(AVERAGE CASE)= %f",n,(float)(end-start)/CLOCKS_PER_SEC);
     start=clock();
     quicksort(x,0,n-1);
     end=clock();
     printf("\n%li sorted integers quick sort(Worst CASE)= %f",n,(float)(end-start)/CLOCKS_PER_SEC);
     start=clock();
     mergesort(a,0,n-1);
     end=clock();
     printf("\n%li unsorted integers merge sort(Best/Worst CASE)= %f",n,(float)(end-start)/CLOCKS_PER_SEC);
}


/*

OUTPUT:

Enter name of the file: 10000
Enter no. of integers: 10000
10000 unsorted integers quick sort(AVERAGE CASE)= 0.000000
10000 sorted integers quick sort(Worst CASE)= 0.062000
10000 unsorted integers merge sort(Best/Worst CASE)= 0.000000

Enter name of the file: 20000
Enter no. of integers: 20000
20000 unsorted integers quick sort(AVERAGE CASE)= 0.000000
20000 sorted integers quick sort(Worst CASE)= 0.172000
20000 unsorted integers merge sort(Best/Worst CASE)= 0.016000

Enter name of the file: 30000
Enter no. of integers: 30000
30000 unsorted integers quick sort(AVERAGE CASE)= 0.015000
30000 sorted integers quick sort(Worst CASE)= 0.282000
30000 unsorted integers merge sort(Best/Worst CASE)= 0.015000

Enter name of the file: 40000
Enter no. of integers: 40000
40000 unsorted integers quick sort(AVERAGE CASE)= 0.016000
40000 sorted integers quick sort(Worst CASE)= 0.391000
40000 unsorted integers merge sort(Best/Worst CASE)= 0.031000

Enter name of the file: 50000
Enter no. of integers: 50000
50000 unsorted integers quick sort(AVERAGE CASE)= 0.000000
50000 sorted integers quick sort(Worst CASE)= 0.516000
50000 unsorted integers merge sort(Best/Worst CASE)= 0.031000
*/