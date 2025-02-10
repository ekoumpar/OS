#include <stdio.h>

int add(int *n1, int *n2, int *n3){
    int sum;
    sum = *n1 + *n2 + *n3;
    return sum;
}

int main(void){

    int n1 = 1;
    int n2 = 2;
    int n3 = 3;

    int sum = add(&n1, &n2, &n3);
    printf("Sum of %d, %d, %d :  %d\n", n1, n2, n3, sum);

    return 0;
}