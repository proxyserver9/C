#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char * prop;
char *word;
char *max_word;
int flag = 1;
int f_exit = 0;
int f_allocated =0;
int f_foundmax = 0;
void input (char **array) {
    getchar();
    char c;
    int length = 0;
    int capacity = 16;

    *array = malloc(sizeof(char) * capacity);

    while ( (c = getchar()) != '\n'){
        if (length + 1 >= capacity){
            capacity++;
            *array = realloc(*array, capacity*sizeof(char));
            if (*array == NULL){ printf("reallocation error\n");
                break;
            }
        }
        (*array)[length++] = c;
    }
    (*array)[length] = '\0';
}

void max_value_word(){
    int i=0;
    //int speciali =0;
    char f_newline = prop[i];
    char c;
    int length = 0;
    int capacity = 1;
    int lengthMaxWord = 0;
    while (f_newline != '\0'){
        word = malloc(sizeof(char) * capacity);
        while((c = prop[i]) != ' ' && c != '\0'){
            if (length + 1 >= capacity){
                capacity++;
                word = realloc(word, capacity*sizeof(char));
            if (word == NULL){
                printf("reallocation error\n");
                break;
            }
            }
            word[length++] = c;
            i++;
        }
        word[length] = '\0';
        //printf("%s-word\n",word);

        if (strlen(word) >= lengthMaxWord){
            if(max_word != NULL){
                free(max_word);
                max_word = NULL;
            }
            max_word = malloc(sizeof(char)*length);
            for (int ii = 0; ii<length; ii++){
                max_word[ii] = word[ii];
            }
            lengthMaxWord = length;
        }

        //printf("%d-maxwordSIZE\n",sizeof(max_word));

        //printf("%s-wordmax\n",max_word);

        while(c == ' ' && c != '\0'){
            if (word != NULL){
            free(word);
            word = NULL;
            }
            c = prop[++i];
        }
        length = 0;
        capacity = 1;
        f_newline = prop[i];
    }

}

void output_screen(){
    //printf("\nyour array\n");
        printf("%s\n", prop);
}

void final(){
    //printf("\nyour array\n");
        printf("%s - ultimul cel mai mare cuvant\n", max_word);
}
int main() {
    int a = 10;
    while(!f_exit){
    switch (a){
        case 0:
            f_exit=1;
            break;

        case 1:
            if(f_allocated){
                output_screen();
            }
            a = 10;
            flag=1;
            break;

        case 2:
            if(!f_allocated){
            printf("introduceti un sir de caractere:");
            input(&prop);
            f_allocated = 1;
            }
            else printf("this step was not executed.");
            a = 10;
            flag = 1;
            break;

        case 3:
            if(f_allocated){
                max_value_word();
                f_foundmax = 1;
            }
            else printf("this step was not executed.");

            a = 10;
            flag = 1;
            break;

        case 4:
            if(f_foundmax){
                final();
            }
            else printf("this step was not executed.");
            a = 10;
            flag = 1;
            break;

        default:
            if (!flag) {
                printf("Invalid option.\n");
            }
            flag = 0;
            printf("Alegeti din meniu 0-exit, 1-output, 2-allocate sir, 3-gasirea cel mai mare cuvant, 4-afisarea rezultatului: ");
            scanf("%d",&a);

    }
    }
    return 0;
}
