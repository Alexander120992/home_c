#include <stdio.h>

int main() {
    int num, min;
    
    scanf("%d", &min);

    for (int i = 1; i < 5; i++) {
        scanf("%d", &num);
        if (num < min) {
            min = num;
        }
    }
    
    printf("%d\n", min);
    
    return 0;
}
