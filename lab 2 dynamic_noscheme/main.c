#include <stdio.h>
#include <stdlib.h>

int main(){
    int MaxElements_Table;

    printf ("Introduceti numarul de elemente dorite ale tabloului: ");
    scanf (" %d", &MaxElements_Table);

    int *Table = (int *)malloc(sizeof(int) * MaxElements_Table);
    int i;

    printf ("introduceti(prin spatiu), elementele(numere intregi) tabloului:\n");
    for (i = 0 ; i < MaxElements_Table; i++){
        printf("T[%d]=", i + 1);
        scanf (" %d" , &Table[i]);
    }

    int Minim = Table[0];
    for (i = 0; i < MaxElements_Table; i++){
        if (Minim > Table[i]) Minim = Table[i];
    }
    printf ( "Cel mai mic element este %d\nPozitia elementelor cu valoarea minima: " , Minim );

    int Prod_PozitiveElements = 1, Flag_PozitiveElements = 0;
    for (i = 0; i < MaxElements_Table; i++){
        if (Minim == Table[i]) {
            printf("%d, ",i + 1);
        }
        if (Table[i] > 0) {
            Prod_PozitiveElements *= Table[i];
            Flag_PozitiveElements = 1;
        }
    }

    if (Flag_PozitiveElements == 1) printf("\nProdusul elementelor pozitive este: %d", Prod_PozitiveElements);
    else printf("\nIn tablou NU SUNT elemente pozitive pentru calcularea produsului lor");

    free (Table);
    Table = NULL;

    return 0;
}