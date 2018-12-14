#include <stdio.h>
#include <stdlib.h>
#define SIZE 30

int Array[SIZE][SIZE];
int distance[SIZE];
int tops[SIZE];
// Заповнення матриці нулями
void zeroArray()
{
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
           Array[i][j]=0;
}

// Запис дуг в матрицю
void enterEdges()
{
    printf("Enter edges:\n");
    int r, c, n;
    for(int i=0; i<49; i++)
    {
        scanf("%d %d %d", &r, &c, &n);
        Array[r-1][c-1]=n;
        Array[c-1][r-1]=n;
    }
}

// Вивід матриці графа
void printArray()
{
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            printf("%d ", Array[i][j]);
        }
        printf("\n");
    }
}

// Ініціалізація масивів відстаней та вершин
void initArray()
{
    for(int i=0; i<SIZE; i++)
    {
        distance[i]=10000;
        tops[i]=1;
    }
    distance[0]= 0;
}

// Вивід найкоротших відстаней до вершин 1-30
void printDistance()
{
    printf("\nShortest path to every vertex(1-30): \n");
        for(int i=0; i<SIZE; i++)
        {
            printf("%d) %d;  ", i+1, distance[i]);
            if((i+1)%5==0 && i!=0)
              printf("\n");
        }
}



// Головна функція
int main(void)
{
    int temp;
    int minindex;
    int min;

    zeroArray();

    enterEdges();

    printArray();

    initArray();


    // Основний алгоритм
    do
    {
        minindex=10000;
        min=10000;
        for (int i=0; i<SIZE; i++)
        {
            if ((tops[i]==1) && (distance[i]<min))
            {
                min=distance[i];
                minindex=i;
            }
        }

        if(min!=10000)
        {
            for(int i=0; i<SIZE; i++)
            {
                if(Array[minindex][i]>0)
                {
                    temp=min+Array[minindex][i];
                    if(temp<distance[i])
                    {
                        distance[i]=temp;
                    }
                }
            }
            tops[minindex]=0;
        }
    }
    while(minindex < 10000);
    printDistance();

  // Відновлення шляху
    int ver[SIZE];
    int end = 29;
    ver[0] = end + 1;
    int k = 1;
    int weight = distance[end];
    while (end > 0)
    {
        for(int i=0; i<SIZE; i++)
            if (Array[end][i] != 0)
            {
                 temp = weight - Array[end][i];
                if (temp == distance[i])
                {
                    weight = temp;
                    end = i;
                    ver[k] = i + 1;
                    k++;
                }
            }
    }

    // Вивід шляху (початкова вершина опинилась в кінці масиву з k елементів)
    printf("\nOutput of the shortest path:\n");
    for(int i = k-1; i>=0; i--)
        printf("%3d ", ver[i]);

    scanf("%d", &temp);
    return 0;
}
