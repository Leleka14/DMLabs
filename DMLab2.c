#include <stdio.h>

int main()
{
    int a;
    printf("Amount of elements in array A = ");
    scanf("%i", &a);
    int A[a];
    int k;
    
    for (int i = 0; i < a; i++) 
    {
		do 
		{
			k = 0;
			printf("A[%d]: ",i+1);
			scanf("%i", &A[i]);
				for (int j = 0; j < i; j++) 
				{
					if (A[i] == A[j])
						k++;		
				}
		}
		while (k > 0);
	}
	int b;
    printf("Amount of elements in array B = ");
    scanf("%i", &b);
    int B[b];
    int j = 0;
    for (int i = 0; i < b; i++) 
    {
		do 
		{
			
			printf("B[%d]: ",i+1);
			scanf("%i", &B[i]);
				for (int k = 0; k < i; k++) 
				{
					if (B[i] == B[k])
						j++;		
				}
		}
		while (j > 0);
	}
	//Об'єднання Множин А і В
	printf("Union of arrays = {");
	for(int i = 0; i < a; i++)
	{
	    int x = 1;
	    for(int k = 0; k < b; k++)
	    {
	        if(A[i] == B[k])
	            x = 0;
	    }
	    if(x == 1)
	        printf("%i", A[i]);
	}
	for(int k = 0; k < b; k++)
	{
	    printf("%i", B[k]);
	}
	printf("}\n");
	//Перетин отриманої множини з множиною А. Доведення закону поглинання
	printf("Intersection united arrays A and B with array A = {");
	for(int i = 0; i < a; i++)
	{
	    if(B[k] != A[i])
	        printf("%i", A[i]);
	    else 
	        printf("%i", B[k]);
	}
	printf("}\n");
}
