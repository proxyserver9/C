#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int xASCII = 0;     //switch variable
int iFor_t = 0;     //counter
char c = 'c';       //one char storage

char t[4] = {'c', 'c','\0','\0'};   //char array for input c-variable
    //same as char t[] = "cc"; //initialization => t[4]
    //acces => t[2 & 3] -null terminators

int flag = 1;           //invalidity of option, line 88 if statement
int f_allocated = 0;    //if the table with struct elements was allocated
int f_exit = 0;         //exit flag, line 64
int f_completed = 0;         //exit flag, line 64

struct M {
    char *name;
    char *country;
    char *director;
    char *genre;
    int year;
};
typedef struct M Movie;
Movie *movies;
int Num_Movies;

void allocation (Movie **array) {
    printf("enter number of movies: ");
    scanf("%d", &Num_Movies);
    getchar();

    *array = malloc(Num_Movies *sizeof(Movie));

    if(*array == NULL){
        printf("allocation failed.\n");
    }
    else printf ("successful allocation.\n");

    f_allocated = 1;
}   // 1

void input (char **array) {
    char cc;
    int length = 0;
    int capacity = 16;

    *array = malloc(sizeof(char) * capacity);
    jump:
    while ( (cc = getchar()) != '\n'){
        if (length + 1 >= capacity){
            capacity++;
            *array = realloc(*array, capacity*sizeof(char));
            if (*array == NULL){ printf("reallocation error\n");
                break;
            }
        }
        (*array)[length++] = cc; // derefentierea
    }
    if (length != 0)(*array)[length] = '\0';
    else if (length == 0) goto jump;
}//citeste pana la '\n' de la tastatura

void input_file(char **array, FILE *ptr) {
    char c;
    int length = 0;
    int capacity = 16;

    *array = malloc(sizeof(char) * capacity);

    while ( (c = fgetc(ptr)) != '\n'){
        if (length + 1 >= capacity){
            capacity++;
            *array = realloc(*array, capacity*sizeof(char));
            if (*array == NULL){ printf("reallocation error\n");
                break;
            }
        }
        (*array)[length++] = c; // derefentierea
    }
    (*array)[length] = '\0';
}  //citeste pana la '\n' din file

void complete_keyboard(){
    int iForTable_movies = 0;
    for(int i = 0; i<Num_Movies; i++){
        printf("input for movie %d:\n",i+1);
        if (iForTable_movies ==0) {
            input(&movies[i].name);
            iForTable_movies++;
        }
        if (iForTable_movies == 1) {
            input(&movies[i].country);
            iForTable_movies++;
        }
        if (iForTable_movies == 2) {
            input(&movies[i].director);
            iForTable_movies++;
        }
        if (iForTable_movies == 3) {
            input(&movies[i].genre);
            iForTable_movies++;
        }
        if (iForTable_movies == 4) {
            scanf("%d", &movies[i].year);
            getchar();
        }
        iForTable_movies = 0;
    }

    f_completed = 1;
}   // 2

void complete_file() {
    FILE *fp;
    fp = fopen("C:\\Users\\Daria Ro\\Desktop\\repositories\\C\\lab 6\\text.txt", "r");

    int iForTable_movies = 0;
    for(int i = 0; i<Num_Movies; i++){
        if (iForTable_movies == 0) {
            input_file(&movies[i].name, fp);
            iForTable_movies++;
        }
        if (iForTable_movies == 1) {
            input_file(&movies[i].country, fp);
            iForTable_movies++;
        }
        if (iForTable_movies == 2) {
            input_file(&movies[i].director, fp);
            iForTable_movies++;
        }
        if (iForTable_movies == 3) {
            input_file(&movies[i].genre, fp);
            iForTable_movies++;
        }
        if (iForTable_movies == 4) {
            fscanf(fp,"%d", &movies[i].year);
            fgetc(fp);
        }
        iForTable_movies = 0;
    }

    f_completed = 1;
    fclose(fp);
}  // 10

void output_screen(){
    printf("\nmovies entered:\n");
    for(int i = 0; i < Num_Movies; i++){
        printf("%d. %s, %s, %s, %s, %d\n", i + 1, movies[i].name, movies[i].country, movies[i].director, movies[i].genre, movies[i].year);
    }
}   // 11

void output_file(){
    FILE *fp;
    fp = fopen("output.txt", "w");
    for(int i = 0; i < Num_Movies; i++){
        fprintf(fp,"%d. %s, %s, %s, %s, %d\n", i + 1, movies[i].name, movies[i].country, movies[i].director, movies[i].genre, movies[i].year);
    }
    fclose(fp);
}

int elemEdit(int i) {
    int iForTable_movies = 0;
    int f_error = 1;

    free(movies[i].name);
    movies[i].name = NULL;
    free(movies[i].country);
    movies[i].country = NULL;
    free(movies[i].director);
    movies[i].director = NULL;
    free(movies[i].genre);
    movies[i].genre = NULL;

    while (f_error) {
        printf("input for movie %d:\n",i+1);
        if (iForTable_movies ==0) {
            input(&movies[i].name);
            if (movies[i].name != NULL) f_error = 0;
            iForTable_movies++;
        }
        if (iForTable_movies == 1) {
            input(&movies[i].country);
            if (movies[i].country != NULL) f_error = 0;
            iForTable_movies++;
        }
        if (iForTable_movies == 2) {
            input(&movies[i].director);
            if (movies[i].director != NULL) f_error = 0;
            iForTable_movies++;
        }
        if (iForTable_movies == 3) {
            input(&movies[i].genre);
            if (movies[i].genre != NULL) f_error = 0;
            iForTable_movies++;
        }
        if (iForTable_movies == 4) {
            scanf("%d", &movies[i].year);
            getchar();
        }
    }
}

char *nameverify;
int find(){
    int f_found = 0;
    if (nameverify != NULL) {
        free(nameverify);
        nameverify = NULL;
    }
    int movieindex = -1;
    printf("introduceti nume filmului cautat: ");
    input(&nameverify);
    for(int i = 0; i < Num_Movies; i++) {
        if (strlen(nameverify) == strlen(movies[i].name)) {
            f_found = 1;
            for (int ii = 0; ii < strlen(movies[i].name); ii++) {
                if (nameverify[ii] != movies[i].name[ii]) {
                    f_found = 0;
                    ii = strlen(movies[i].name);
                    break;
                }
            }
            if (f_found){movieindex = i;  i = Num_Movies; break;}
        }
    }
    if (!f_found) {printf("filmul nu a fost gasit\n"); return movieindex = -1;}
    else if (f_found) return movieindex;
}

Movie *temp;
void TempCopying (int i) {
    temp[i].name = movies[i].name;
    temp[i].country = movies[i].country;
    temp[i].director = movies[i].director;
    temp[i].genre = movies[i].genre;
    temp[i].year = movies[i].year;
}
void MovieCopying (int i) {
    movies[i].name = temp[i].name;
    movies[i].country = temp[i].country;
    movies[i].director = temp[i].director;
    movies[i].genre = temp[i].genre;
    movies[i].year = temp[i].year;
}

void  deletebyName() {
    temp = malloc(sizeof(Movie)*(Num_Movies-1));
    int movieindex = find();
    if (movieindex != -1){
        for (int ii = 0; ii < movieindex; ii++) {
            TempCopying(ii);
        }
        for (int i = movieindex; i < Num_Movies-1; i++) {
            temp[i].name = movies[i+1].name;
            temp[i].country = movies[i+1].country;
            temp[i].director = movies[i+1].director;
            temp[i].genre = movies[i+1].genre;
            temp[i].year = movies[i+1].year;
        }
        Num_Movies--;
        movies = realloc(movies, Num_Movies*sizeof(Movie));
        for (int i = 0; i < Num_Movies; i++) {
            MovieCopying(i);
        }
    }
    temp = NULL;
    if (Num_Movies == 0) {
        free(movies);
        movies = NULL;
        f_completed = 0;
    }
}

void newElemEnd() {
    int iForTable_movies = 0;
    Num_Movies++;
    movies = realloc(movies,sizeof(Movie)*(Num_Movies));
    printf("input for new appended movie:\n");

    if (iForTable_movies ==0) {
        input(&movies[Num_Movies-1].name);
        iForTable_movies++;
    }
    if (iForTable_movies == 1) {
        input(&movies[Num_Movies-1].country);
        iForTable_movies++;
    }
    if (iForTable_movies == 2) {
        input(&movies[Num_Movies-1].director);
        iForTable_movies++;
    }
    if (iForTable_movies == 3) {
        input(&movies[Num_Movies-1].genre);
        iForTable_movies++;
    }
    if (iForTable_movies == 4) {
        scanf("%d", &movies[Num_Movies-1].year);
        getchar();
    }
}

void sortbyName() {
    for (int i = 0; i < Num_Movies - 1; i++) {
        for (int j = i + 1; j < Num_Movies; j++) {

            if (strcmp(movies[i].name, movies[j].name) > 0) {
                Movie Temp = movies[i];
                movies[i] = movies[j];
                movies[j] = Temp;
            }
        }
    }
}

void freetableMovies() {
    if (movies == NULL) return;
    movies = realloc(movies, Num_Movies*sizeof(Movie));
    free(movies);
    movies = NULL;
    Num_Movies = 0;
    f_completed = 0;
    f_allocated = 0;
}

void default_block() {
    t[0] = 'c';
    t[1] = 'c';
    t[2] = '\0';
    t[3] = '\0';
    xASCII = 0;
    iFor_t = 0;
    flag = 1;
}  //for default values

int main() {
    while (!f_exit){
    switch(xASCII){
        case 49:    //1 - number of movies => aloc table
            if(!f_allocated) {              //prevent memory leak
                allocation(&movies);
            }
            else printf("This step was not executed.\n");
            default_block();
            break;

        case 50:    //2 - complete keyboard
            if(f_allocated && !f_completed) {
                complete_keyboard();
            }
            else printf ("This step was not executed.\n");
            default_block();
            break;

        case 51:    //3 - search elem (&output on screen)
            if(f_completed) {
                int index = find();
                if (index > -1) {
                    printf("%d. %s, %s, %s, %s, %d\n", index + 1, movies[index].name, movies[index].country, movies[index].director, movies[index].genre, movies[index].year);
                }
            }
            else printf("This step was not executed.\n");
            default_block();
            break;

        case 52:    //4 - sort by name alphabetic order
            if(f_completed) {
                sortbyName();
            }
            else printf("This step was not executed.\n");
            default_block();
            break;

        case 53:    //5 - edit elem
            if(f_completed) {
                int index = find();
                if (index > -1) {
                    elemEdit(index);
                }
            }
            else printf("This step was not executed.\n");
            default_block();
            break;

        case 54:    //6 - +new elem at the end
            if(f_completed) {
                newElemEnd();
            }
            else printf("This step was not executed.\n");
            default_block();
            break;

        case 55:    //7 - delete by name
            if (f_completed) {
                deletebyName();
            }
            else printf("This step was not executed.\n");
            default_block();
            break;

        case 56:    //8 - new elem insertion
            if (f_completed) {
                printf("poshol nahui3");
            }
            else printf("This step was not executed.\n");
            default_block();
            break;

        case 57:  //9 - output file
            if(f_allocated ) {
                output_file();
            }
            else printf("This step was not executed.\n");

            default_block();
            break;

        case 4948:  //10 - completare file
            if(f_allocated && !f_completed) {
                complete_file();
            }
            else printf("This step was not executed.\n");

            default_block();
            break;

        case 4949:  //11 - output on screen
            if(f_completed) {
                output_screen();
            }
            else printf("This step was not executed.\n");
            default_block();
            break;

        case 4950:  //12 - free struct table
            if (f_allocated) {
                freetableMovies();
            }
            else printf("This step was not executed.\n");
            default_block();
            break;

        case 48:    //0-exit
            f_exit = 1;
            break;

        default:
            if (!flag) {
                printf("Invalid option.\n");
            }

            printf("Alegeti din meniu: 0-12: ");
            iFor_t = 0;

            while (1) {
                scanf ("%c", &c);
                if(c =='\n') break;
                if(iFor_t < 2){
                    t[iFor_t] = c;
                    iFor_t++;
                }
                else iFor_t++;
            }

            if (iFor_t == 2) xASCII = t[0] * 100 + t[1];
            else if (iFor_t == 1) xASCII = t[0];
            else xASCII = 0;

            t[0] = 'c';
            t[1] = 'c';
            t[2] = '\0';
            t[3] = '\0';
            flag = 0;
            break;
    }
}
    return 0;
}