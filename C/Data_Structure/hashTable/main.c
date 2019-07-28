#include <stdio.h>

int square(const int), cube(const int),multiplier(int, float);

int main(){
    int y, x=5;
    int (*func)(const int);
    
    //Func now = square
    func = square; y = (*func)(x);
    printf("Square of %d is %d\n", x, y);
    //Func now = cube
    func = cube; y=(*func)(x);
    printf("Cube of %d is %d\n", x, y);


    typedef int (*Pfi)(int,float);
    Pfi z[4];

    z[2] = multiplier;
    int result = z[2](5,3.0);
    printf("%d\n",result);
}

int square(const int x) {
    return(x*x);
}

int cube(const int x) {
    return(x*x*x);
}

int multiplier(int a,float b){
    return a*b;
}


