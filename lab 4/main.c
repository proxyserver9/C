/*1. Alocarea dinamică a memoriei pentru tablourile bidimensionale
2. Introducerea elementelor tabloului de la tastatură
3. Completarea tabloului cu valori aleatorii
4. Sortarea elementelor tabloului (Să se sorteze coloanele tabloului în ordine descendentă cu ajutorul metodei “bulelor”)
5. Afișarea elementelor tabloului la ecran
6. Eliberarea memoriei alocate pentru tablou
0. Ieșire din program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i, j;      //i, j for iterations
int i_T;    //T - table index;   i for lines
int j_T;    //j for columns

void complete_pseudo_random(int **Table){

    srand(time(NULL));

 for (i = 0; i < i_T; i++)
 {
  for (j = 0; j < j_T; j++)
  {
      Table[i][j] = rand() % 100;
  }
 }

}

void complete_keyboard(int **Table){

    for (i = 0; i < i_T; i++)
 {
  for (j = 0; j < j_T; j++)
  {
            scanf ("%d", &Table[i][j]);
  }
 }
 //return 0 nu trb
}

void Test_print(int **Table){

    for (i = 0; i < i_T; i++)
 {
  for (j = 0; j < j_T; j++)
  {
            printf ("%d ", Table[i][j]);
  }
  printf ("\n");
 }
 //return 0 nu trb
}

void ColumsElements_Bubblesort (int **Table){
    int temp = 0, flag_sorted = 0;

    while(!flag_sorted){    //sorted=1 recursion stops, unsorted=0 recursion goes
        flag_sorted = 1;

        for (j = 0; j < j_T; j++)
     {
      for (i = 0; i < i_T - 1; i++)
      {
          if(Table[i][j] < Table[i+1][j])
          {
              temp = Table[i][j];
              Table[i][j] = Table[i+1][j];
              Table[i+1][j] = temp;

              flag_sorted = 0;     // matches the sorting state : sorted=1 || unsorted=0
          }
      }
     }
    }
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
 scanf ("%d", &a);

 if (a == 1) complete_keyboard(T);
 else if (a == 2) complete_pseudo_random(T);
 else printf ("Ati introdus numarul gresit");

 ColumsElements_Bubblesort(T);

 Test_print(T);

 //

 for (i = 0; i < i_T; i++) free(T[i]);
    free(T);    //free memory
    T = NULL;   //ocistka adresa, nevalidnosti

 return 0;
}