#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void revinsertion(int x[],int n)
{
    int i,j,val;
    for(i=0;i<n-1;i++)
    {
        val=x[i+1];
        for(j=i;j>=0;j--)
        {
            if(val>x[j])
                x[j+1]=x[j];
            else break;
        }
        x[j+1]=val;
    }
}
void insertionsort(int x[],int n)
{
    int i,j,val;
    for(i=0;i<n-1;i++)
    {
        val=x[i+1];
        for(j=i;j>=0;j--)
        {
            if(val<x[j])
                x[j+1]=x[j];
            else break;
        }
        x[j+1]=val;
    }
}

void selectionsort(int x[],int n)
{
    int i,j,pos,min;
    for(i=0;i<n-1;i++)
     {
         pos=i;
         min=x[i];
         for(j=i+1;j<n;j++)
         {
             if(x[j]<min)
             {
                 min=x[j];
                 pos=j;
             }
         }
         x[pos]=x[i];
         x[i]=min;
     }
}
void main()
{
     int i;
     clock_t start,end;
     FILE *fp;
     char str[50];
     long int n;
     int x[50000],a[50000];
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
     start=clock();
     insertionsort(x,n);
     end=clock();
     printf("%li unsorted integers insertion sort(AVERAGE CASE)= %f",n,(float)(end-start)/CLOCKS_PER_SEC);
     start=clock();
     insertionsort(x,n);
     end=clock();
     printf("\n%li sorted integers insertion sort(BEST CASE)= %f",n,(float)(end-start)/CLOCKS_PER_SEC);
     revinsertion(x,n);
     start=clock();
     insertionsort(x,n);
     end=clock();
     printf("\n%li reverse sorted integers insertion sort(WORST CASE)= %f",n,(float)(end-start)/CLOCKS_PER_SEC);
     while(1)
     {
      if(feof(fp)!=0)
        break;
      fscanf(fp,"%d",&a[i++]);
     }
     start=clock();
     selectionsort(a,n);
     end=clock();
     printf("\n%li unsorted integers selection sort= %f",n,(float)(end-start)/CLOCKS_PER_SEC);
     start=clock();
     selectionsort(a,n);
     end=clock();
     printf("\n%li sorted integers selection sort= %f",n,(float)(end-start)/CLOCKS_PER_SEC);
     revinsertion(a,n);
     start=clock();
     selectionsort(a,n);
     end=clock();
     printf("\n%li reverse sorted integers selection sort= %f",n,(float)(end-start)/CLOCKS_PER_SEC);
}




/*
OUTPUT:

Enter name of the file: case1
Enter no. of integers: 10000
10000 unsorted integers insertion sort(AVERAGE CASE)= 0.083000
10000 sorted integers insertion sort(BEST CASE)= 0.000000
10000 reverse sorted integers insertion sort(WORST CASE)= 0.132000
10000 unsorted integers selection sort= 0.147000
10000 sorted integers selection sort= 0.121000
10000 reverse sorted integers selection sort= 0.132000


Enter name of the file: case2
Enter no. of integers: 20000
20000 unsorted integers insertion sort(AVERAGE CASE)= 0.285000
20000 sorted integers insertion sort(BEST CASE)= 0.000000
20000 reverse sorted integers insertion sort(WORST CASE)= 0.533000
20000 unsorted integers selection sort= 0.525000
20000 sorted integers selection sort= 0.523000
20000 reverse sorted integers selection sort= 0.523000


Enter name of the file: case3
Enter no. of integers: 30000
30000 unsorted integers insertion sort(AVERAGE CASE)= 0.617000
30000 sorted integers insertion sort(BEST CASE)= 0.000000
30000 reverse sorted integers insertion sort(WORST CASE)= 1.191000
30000 unsorted integers selection sort= 1.178000
30000 sorted integers selection sort= 1.175000
30000 reverse sorted integers selection sort= 1.175000


Enter name of the file: case4
Enter no. of integers: 40000
40000 unsorted integers insertion sort(AVERAGE CASE)= 1.094000
40000 sorted integers insertion sort(BEST CASE)= 0.000000
40000 reverse sorted integers insertion sort(WORST CASE)= 2.133000
40000 unsorted integers selection sort= 2.090000
40000 sorted integers selection sort= 2.095000
40000 reverse sorted integers selection sort= 2.092000


Enter name of the file: case5
Enter no. of integers: 50000
50000 unsorted integers insertion sort(AVERAGE CASE)= 1.667000
50000 sorted integers insertion sort(BEST CASE)= 0.000000
50000 reverse sorted integers insertion sort(WORST CASE)= 3.326000
50000 unsorted integers selection sort= 3.269000
50000 sorted integers selection sort= 3.265000
50000 reverse sorted integers selection sort= 3.265000
*/