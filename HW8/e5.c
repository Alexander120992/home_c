#include <stdio.h>

int find_max_array(int size, int a[]) {
    int max = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int main() {
    int arr[] = {3, 7, 1, 9, 4, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int max = find_max_array(size, arr);
    printf("%d\n", max);
    return 0;
}
