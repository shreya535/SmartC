#include <stdio.h>
#include "myheader.h"



int main() {
    float radius = 5.0;
    float area = 3.14 * radius * radius; // calculate area
    int i, sum = 0;

    for(i = 0; i < 100; i++) {
        sum += i;
    }

    char c = 'A';
    char *str = "Hello World";

    if(sum >= 1000 && radius < 10) {
        printf("%s: %d\n", str, sum);
    } else {
        printf("Not enough\n");
    }

    return 0;
}
