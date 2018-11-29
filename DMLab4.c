#include <stdio.h>

int main (void)
{
	int i,j,k,a;
	int edgeA=18;
    int topA =11;

	   int edge [18][4] =
	   {
	       {1, 2, 4, 0},
	       {1, 3, 3, 0},
	       {1, 4, 1, 0},
	       {2, 5, 2, 0},
	       {2, 7, 1, 0},
	       {3, 5, 7, 0},
	       {3, 6, 7, 0},
	       {4, 6, 2, 0},
	       {4, 7, 2, 0},
	       {5, 8, 4, 0},
	       {5, 9, 4, 0},
	       {6, 8, 4, 0},
	       {6, 10, 5, 0},
	       {7, 9, 3, 0},
	       {7, 10, 3, 0},
	       {8, 11, 7, 0},
	       {9, 11, 6, 0},
	       {10, 11, 5, 0}
	   };

	   int top [11][2] =
	   {
	       {1, 0},
	       {2, 0},
	       {3, 0},
	       {4, 0},
	       {5, 0},
	       {6, 0},
	       {7, 0},
	       {8, 0},
	       {9, 0},
	       {10, 0},
	       {11, 0}
	   };


	   for (i = 0; i < edgeA; i++)
	   {
	       for (j = 0; j < edgeA - i - 1; j++)
	       {
	           if (edge [j][2] > edge [j + 1][2])
	           {
	               for (k = 0, a = 0; k < 4; k++)
	               {
	                   a = edge [j + 1][k];
	                   edge [j + 1][k] = edge [j][k];
	                   edge [j][k] = a;
	               }
	           }
	       }
	   }

	   int count = 1;
	   for (i = 0; i < edgeA; i++)
	   {
	       if (top [edge[i][0] - 1][1] != top [edge[i][1] - 1][1])
	       {
	           edge [i][3] = 1;
	           if (top [edge[i][0] - 1][1] == 0 && top [edge[i][1] - 1][1] != 0)
	           {
	               top [edge[i][0] - 1][1] = top [edge[i][1] - 1][1];
    		   }
	           if (top [edge[i][0] - 1][1] != 0 && top [edge[i][1] - 1][1] == 0)
	           {
	               top [edge[i][1] - 1][1] = top [edge[i][0] - 1][1];
	           }
	           if (top [edge[i][0] - 1][1] != 0 && top [edge[i][1] - 1][1] != 0)
	           {
	               for (j = 0; j < topA; j++)
	               {
	                   if (top [j][1] == top [edge[i][1] - 1][1])
	                   {
	                       top [j][1] = top [edge[i][0] - 1][1];
	                   }
	               }
	           }
	       }
	       if (top [edge[i][0] - 1][1] == 0 && top [edge[i][1] - 1][1] == 0)
	       {
	           edge [i][3] = 1;
	           top [edge[i][0] - 1][1] = count;
	           top [edge[i][1] - 1][1] = count;
	           count++;
	       }
	   }

	   for (i = 0; i < edgeA; i++)
	   {
	       if (edge[i][3] == 1)
	       {
	           printf ("%i - %i (%i)\n", edge[i][0], edge[i][1], edge [i][2]);
	       }
	   }
	   printf("Tree:");
	   for (i = 0; i < edgeA; i++)
	   {
	       if (edge[i][3] == 1)
	       {
	           printf ("%i - %i     ", edge[i][0], edge[i][1]);
	       }
	   }
	   printf("\n");
	   return 0;
}
