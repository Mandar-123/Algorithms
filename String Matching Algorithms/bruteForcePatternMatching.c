#include <stdio.h>
#include <string.h>

int brute_force(char t[],int n,char p[],int m)
{
    int i,j;
    for(i=0;i<=n-m;i++)
    {
        j=0;
        while(j<m && t[i+j]==p[j])
            j=j+1;
        if(j==m)
            return i;
    }
    return -1;
}

void main()
{
    char t[50],p[50];
    int n,m,result;
    printf("Enter String: \n");
    gets(t);
    printf("Enter Pattern: \n");
    gets(p);
    n=strlen(t);
    m=strlen(p);
    result=brute_force(t,n,p,m);
    if(result==-1)
        printf("Pattern not found");
    else printf("Pattern found at index %d",result);
}







/*

OUTPUT 1:

Enter String:
aaabdcghsjiyarsvjnnnaosyt
Enter Pattern:
svjn
Pattern found at index 14


OUTPUT 2:

Enter String:
moosganxysodgugao
Enter Pattern:
abc
Pattern not found

OUTPUT 3:

Enter String:
10010101110011111
Enter Pattern:
110011
Pattern found at index 8
*/