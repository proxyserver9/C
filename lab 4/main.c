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
    printf ("1. Alocarea dinamică a memoriei pentru tablourile bidimensionale\n2. Introducerea elementelor tabloului de la tastatură\n3. Completarea tabloului cu valori aleatorii\n4. Să se sorteze coloanele tabloului în ordine descendentă cu ajutorul metodei “bulelor”\n5. Afișarea elementelor tabloului la ecran\n6. Eliberarea memoriei alocate pentru tablou\n0. Ieșire din program\n");

    char a = 'p';
    int f_allocated = 0, f_input = 0, f_exit = 0;

    while (!f_exit) {
        switch (a) {
            case '1':
                f_allocated = 1;
                printf ("Numarul de randuri: ");
                scanf ("%d", &i_T);

                printf ("Numarul de coloane: ");
                scanf ("%d", &j_T);

                int **T = (int **)malloc(i_T * sizeof(int *));   //(int **)?     T for Table    double pointer, array of pointers
                for (i = 0; i < i_T; i++) T[i] = (int *)malloc(j_T * sizeof(int));

                a = 'p';
                break;

            case '2':
                if (f_allocated) {
                    complete_keyboard(T); f_input = 1;}
                else printf("This step was not executed\n");
                a = 'p';
                break;

            case '3':
                if (f_allocated) {
                    complete_pseudo_random(T); f_input = 1;}
                else printf("This step was not executed\n");
                a = 'p';
                break;

            case '4':
                if (f_input)
                    ColumsElements_Bubblesort(T);
                else printf("This step was not executed\n");
                a = 'p';
                break;

            case '5':
                if (f_input)
                    Test_print(T);
                else printf("This step was not executed\n");
                a = 'p';
                break;

            case '6':
                if(f_allocated) {
                    for (i = 0; i < i_T; i++) free(T[i]);
                    free(T);
                    T = NULL;
                    printf("memory is no more allocated\n");
                    f_allocated = 0; f_input = 0;}
                else printf("This step was not executed\n");
                a = 'p';
                break;

            case '0':
                f_exit = 1;
                break;

            default:
                printf ("Alegeti conform meniului: alocare-1, keyboard-2, pseudo-3, sort-4 , print-5, free-6, exit-0: ");
                scanf (" %c", &a);
        }

    }

 return 0;
}