#include <stdio.h>

int main() {
    int a, b;

    scanf("%d %d", &a, &b);

    if (a < 0 || b < 0) {
        printf("числа должны быть неотрицательными\n");
        return 1;
    }

    if (a == 0 && b == 0) {
        printf("НОД не определен\n");
        return 1;
    }

    while (b != 0) {
        int temp = b;
        b = a % b;  
        a = temp;
    }

    printf("%d\n", a);
    
    return 0;
}
