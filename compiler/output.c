/* #include <stdio.h> */

/* #include <stdlib.h> */







typedef struct {
    int id;
    float salary;
    char name[50];
} Employee;

enum Day { MON, TUE, WED, THU, FRI, SAT, SUN };

int globalVar = 0;
static int count = 0;

int add(int a, int b) {
    return a + b;
}

float divide(float x, float y) {
    if (y == 0.0f) {
        return 0.0f;
    }
    return x / y;
}

int main() {
    
    int a = 10;
    int b = 255;
    int hex = 0xFF;
    int oct = 017;

    
    float f1 = 3.14f;
    double d1 = 2.718e10;

    
    char ch = 'A';
    char *str = "Hello, World!";

    
    int sum = a + b;
    int diff = a - b;
    int product = a * b;
    int mod = a % b;
    int bits = a & b;
    int shift = a << 2;

    
    a += 5;
    b -= 3;
    count++;
    globalVar--;

    
    if (a == b) {
        printf("equal\n");
    } else if (a != b) {
        printf("not equal\n");
    }

    
    for (int i = 0; i < 100; i++) {
        if (i % 2 == 0) continue;
        if (i > 50) break;
        printf("%d\n", i);
    }

    int x = 0;
    while (x < 10) {
        x++;
    }

    do {
        x--;
    } while (x > 0);

    
    switch (a) {
        case 1:
            printf("one\n");
            break;
        case 2:
            printf("two\n");
            break;
        default:
            printf("other\n");
    }

    
    int max = (a > b) ? a : b;

    
    int *ptr = &a;
    *ptr = 42;

    
    int arr[100];
    arr[0] = 1;

    
    int size = sizeof(int);

    
    int result = add(a, b);
    float div = divide(f1, d1);

    
    Employee emp;
    emp.id = 1;
    emp.salary = 50000.0f;

    
    enum Day today = MON;

    
    int casted = (int)f1;

    
    if (a > 0 && b > 0) {
        printf("both positive\n");
    }
    if (a < 0 || b < 0) {
        printf("one negative\n");
    }

    return 0;
}