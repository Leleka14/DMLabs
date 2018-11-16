#include <stdio.h>
#include <math.h>

int main()
{
    
    
    int size;
    int a, b;
    printf("What is size of arrays?: ");
    scanf("%d", &size);
    printf("\n");
    int A[size];
    for(a=0; a<size; a++)
    {
        printf("A[%d] = ", a+1);
        scanf("%d", &A[a]);
        printf("\n");
    }
    int B[size];
    for(b=0; b<size; b++)
    {
        printf("B[%d] = ", b+1);
        scanf("%d", &B[b]);
        printf("\n");
    }
    printf("A = ");
    for(a=0; a<size; a++)
    {
        printf("%d ", A[a]);
    }
    printf("\n");
    
    printf("B = ");
    for(b=0; b<size; b++)
    {
        printf("%d ", B[b]);
    }
    printf("\n");
    int matrix[size][size];
    int i, j;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            if(5*A[i]-(B[j])>3)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }
    printf("\n");
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            printf("%d ", matrix[i][j]);
            if(j==size-1)
                printf("\n");
        }
    }
    printf("\n");
    printf("This matrix is:\n");
    int diagonal=1;
    for(i=0; i<size; i++)
    {
        if (matrix[i][i]==0)
            diagonal=0;
    }
    if(diagonal==1)
        printf("Reflexive.\n");
    else if(diagonal==0)
        printf("Not reflexive.\n");
    int diagonal1=0;
    for(i=0; i<size; i++)
    {
        if (matrix[i][i]==1)
            diagonal1=1;
    }
    if(diagonal1==0)
        printf("Antireflexive.\n");
    else if(diagonal1==1)
        printf("Not antireflexive.\n");
    int diagonal2=1;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            if((i!=j) && (matrix[j][i]!=matrix[i][j]))
                diagonal2 = 0;
        }
    }
    
    if(diagonal2==1)
        printf("Symmetric\n");
    else if(diagonal2==0)
        printf("Not symmetric\n");
}
