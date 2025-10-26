#include <stdio.h>
#include <math.h>
float px,x1,x2,a,b,c,x,F;   int i=1;

int main(){
    printf("Introduceti(prin space) valorile pentru: px, x1, x2, a, b, c:\n");
    scanf("%f %f %f %f %f %f",&px,&x1,&x2,&a,&b,&c);
    if(px<0) x=x2;
    else x=x1;
    while(x<=x2 && x>=x1){
        if (x<0 && b!=0) F=a-cos(x)/(10+b);
        else if (x>0 || b==0) F=(x-a)*(x-b);
        else F=3*pow(x,2)+a/c;
        printf("%d. %f    %f\n", i,x,F);
        x=x+px;
        i++;
    }
    return 0;
}