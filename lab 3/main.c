//Să se determine suma elementelor negative din fiecare linie și
//media aritmetica elementului maximal și cel minimal.     Tablou bidimens.
#include <stdio.h>
#include <stdlib.h>

int i, j;      //i, j for iterations
int i_T;    //T - table index;   i for lines
int j_T;    //j for columns

int Min_Max_media(int **Table){

    int min = Table[0][0], max = Table[0][0];

    for (i = 0; i < i_T; i++)
    {
        for (j = 0; j < j_T; j++)
        {
            if (Table[i][j] < min) min = Table[i][j];
            else if (Table[i][j] > max) max = Table[i][j];
        }
    }

    float media = (min + max) / 2.0f;

    return printf ("Media aritmetica a elementului maxim si minim: %f\n", media);
}


int Sum_each_row(int **Table){

    int sum = 0;

    for (i = 0; i < i_T; i++)
    {
        for (j = 0; j < j_T; j++)
        {
            if (Table[i][j] < 0) sum += Table[i][j];
        }

        printf ("Suma pe randul %d: %d\n", i+1, sum);
        sum = 0;
    }

    return 0;

}


int main() {

    printf ("Numarul de randuri: ");
    scanf ("%d", &i_T);

    printf ("Numarul de coloane: ");
    scanf ("%d", &j_T);

    int **T = (int **)malloc(i_T * sizeof(int *));   //(int **)?     T for Table

    for (i = 0; i < i_T; i++)
    {
        T[i] = (int *)malloc(j_T * sizeof(int));    //(int *)?
        for (j = 0; j < j_T; j++)
        {
            scanf(" %d", &T[i][j]);
        }
    }       //*(*(arr + row) + col)     samen|| T [i][j] || *(*(T + i) + j)
    //*(arr + row) same arr[row]

    Min_Max_media (T);
    Sum_each_row (T);

    free (T);
    T = NULL;

    return 0;
}