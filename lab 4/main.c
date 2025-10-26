//Să se determine suma elementelor negative din
//fiecare linie și media elementului maximal și cel minimal.     Tablou bidimens.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i, j;      //i, j for iterations
int i_T;    //T - table index;   i for lines
int j_T;    //j for columns

void complete_pseudo_random(int **Table){

    srand(time(NULL));       //creating seed

    for (i = 0; i < i_T; i++)
    {
        for (j = 0; j < j_T; j++)
        {
            Table[i][j] = rand();
        }
    }

}

int complete_keyboard(int **Table){

    for (i = 0; i < i_T; i++)
    {
        for (j = 0; j < j_T; j++)
        {
            scanf("%d", &Table[i][j]);
        }
    }

    return 0;

}

int Test_print(int **Table){

}


int main() {

    printf ("Numarul de randuri: ");
    scanf ("%d", &i_T);

    printf ("Numarul de coloane: ");
    scanf ("%d", &j_T);

    int **T = (int **)malloc(i_T * sizeof(int *));   //(int **)?     T for Table
    //double pointer, array of pointers

    for (i = 0; i < i_T; i++)
    {
        T[i] = (int *)malloc(j_T * sizeof(int));    //(int *)?
    }
    //*(*(arr + row) + col)     samen|| T [i][j] || *(*(T + i) + j)
    //*(arr + row) same arr[row]

    int a = 0;
    printf ("Metoda 1. Introducerea elementelor tabloului de la tastatură\n");
    printf ("Metoda 2. Completarea tabloului cu valori aleatorii\n");
    printf ("Alegeti: pentru metoda 1 tastati 1, pentru cealalta 2: ");
    scanf ("%d", a);

    if (a == 1) complete_keyboard(T);
    else complete_pseudo_random(T);


    return 0;
}