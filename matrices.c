#include<stdio.h>

int main()
{

    int n, m, c, d, m1[10][10], m2[10][10], add[10][10], sub[10][10];
    printf("\nEnter the number of rows and columns of the matrices \n\n");
    scanf("%d%d", &m, &n);

    printf("\nEnter the %d elements of the first matrix \n\n", m*n);
    for(c = 0; c < m; c++)  
        for(d = 0; d < n; d++)  
            scanf("%d", &m1[c][d]);

    printf("\nEnter the %d elements of the second matrix \n\n", m*n);
    for(c = 0; c < m; c++)  
        for(d = 0; d < n; d++)  
            scanf("%d", &m2[c][d]);

 
    printf("\n\nThe first matrix is: \n\n");
    for(c = 0; c < m; c++)  
    {
        for(d = 0; d < n; d++)  
        {
            printf("%d\t", m1[c][d]);
        }
    printf("\n");
    }

 
    printf("\n\nThe second matrix is: \n\n");
    for(c = 0; c < m; c++)
    {
        for(d = 0; d < n; d++)  
        {
            printf("%d\t", m2[c][d]);
        }
    printf("\n");
    }

   
    for(c = 0; c < m; c++)
        for(d = 0; d < n; d++)
            add[c][d] = m1[c][d] + m2[c][d];


    printf("\n\nThe sum of the two entered matrices is: \n\n");
    for(c = 0; c < m; c++)
    {
        for(d = 0; d < n; d++)
        {
            printf("%d\t", add[c][d]);
        }
        printf("\n");
    }

   
    for(c = 0; c < m; c++)
        for(d = 0; d < n; d++)
            sub[c][d] = m1[c][d] - m2[c][d];

   
    printf("\n\nThe difference(subtraction) of the two entered matrices is: \n\n");
    for(c = 0; c < m; c++)
    {
        for(d = 0; d < n; d++)
        {
            printf("%d\t", sub[c][d]);
        }
        printf("\n");
    }
   
   
        printf("\nRow Sum....\n");
    for(c=0;c<m;c++)  
    {
        int rsum=0;
        for(d=0;d<n;d++)
        {
            rsum=rsum+m1[c][d];
        }
        printf("\nSum of all the elements in row %d is %d\n",c,rsum);
    }
    printf("\nColumn Sum....\n");
    for(c=0;c<m;c++)
    {
        int csum=0;
        for(d=0;d<n;d++)
        {
            csum=csum+m1[d][c];
        }
        printf("\nSum of all the elements in column %d is %d\n",c,csum);
    }

    return 0;
}
