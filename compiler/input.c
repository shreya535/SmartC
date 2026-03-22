#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    if (n == 0)
        return 1
    return n * factorial(n - 1)
}

int isPrime(int n) {
    int i;
    if (n < 2)
        return 0;
    for (i = 2; i < n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1
}

void printArray(int arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n")
}

int main() {
    int n = 5;
    int result;
    int numbers[5] = {1, 2, 3, 4, 5};

    result = factorial(n)
    printf("Factorial of %d is %d\n", n, result);

    if (isPrime(n))
        printf("%d is prime\n", n);
    else
        printf("%d is not prime\n", n)

    printArray(numbers, 5);

    int x;
    int y = x + 10;
    printf("y = %d\n", y);

    undeclaredFunc();

    return 0
}