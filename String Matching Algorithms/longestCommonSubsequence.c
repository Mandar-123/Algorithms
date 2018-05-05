#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
    return(a>b?a:b);
}
void lcs( char X[], char Y[], int m, int n )
{
   int L[50][50],i,j,index;
   char sol[50];
   for(i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
   i=m;
   j=n;
   index = L[m][n];
   sol[index] = '\0';
   while (i > 0 && j > 0)
   {
      if (X[i-1] == Y[j-1])
      {
          sol[index-1] = X[i-1];
          i--;
          j--;
          index--;
      }
      else if (L[i-1][j] > L[i][j-1])
         i--;
      else j--;
   }
    printf("LCS of %s and %s is %s ",X,Y,sol);
    printf("\nLength of Subsequence= %d",strlen(sol));
}
void main()
{
  char X[50],Y[50];
  printf("Enter 1st Sequence:\n");
  scanf("%s",X);
  printf("Enter 2nd Sequence:\n");
  scanf("%s",Y);
  lcs(X, Y,strlen(X),strlen(Y));
}

/*

OUTPUT:

Enter 1st Sequence:
nasucgbikbwdkfag
Enter 2nd Sequence:
akhsbcvawbdjayvdmn
LCS of nasucgbikbwdkfag and akhsbcvawbdjayvdmn is akbwda
Length of Subsequence= 6

Enter 1st Sequence:
gtacodnaprosbxi
Enter 2nd Sequence:
nxpahgsxmla
LCS of gtacodnaprosbxi and nxpahgsxmla is npsx
Length of Subsequence= 4
*/
