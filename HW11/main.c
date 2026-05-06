#include <stdio.h>
#include "temp_api.h"

int main() {
    struct temperature data[] = {
        {2024, 1, 15, 12, 30, -5},
        {2024, 1, 16, 14, 0, -3},
        {2024, 1, 17, 10, 15, -8},
        {2024, 2, 5, 11, 0, 2},
        {2024, 2, 10, 13, 45, 5},
        {2024, 2, 20, 16, 30, 0},
        {2024, 3, 1, 9, 0, 10},
        {2024, 3, 15, 12, 0, 15},
        {2024, 3, 25, 8, 30, 12}
    };
    
    int size = sizeof(data) / sizeof(data[0]);
    
    print_month_stats(data, size, 1);
    print_month_stats(data, size, 2);
    print_month_stats(data, size, 3);
    
    print_year_stats(data, size);
    
    return 0;
}
