#include <stdio.h>

int main() {
    int arr[10], max_idx = 0, min_idx = 0;

    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < 10; i++) {
        if (arr[i] > arr[max_idx]) max_idx = i;
        if (arr[i] < arr[min_idx]) min_idx = i;
    }

    printf("%d %d %d %d\n", max_idx + 1, arr[max_idx], min_idx + 1, arr[min_idx]);

    return 0;
}
