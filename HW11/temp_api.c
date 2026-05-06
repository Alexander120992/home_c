#include <stdio.h>
#include "temp_api.h"

void print_month_stats(struct temperature data[], int size, int month) {
    int sum = 0, count = 0;
    int min = 99, max = -99;
    
    for (int i = 0; i < size; i++) {
        if (data[i].month == month) {
            sum += data[i].temp;
            count++;
            if (data[i].temp < min) min = data[i].temp;
            if (data[i].temp > max) max = data[i].temp;
        }
    }
    
    if (count > 0) {
        printf("Month %02d statistics:\n", month);
        printf("  Average temperature: %.2f\n", (float)sum / count);
        printf("  Minimum temperature: %d\n", min);
        printf("  Maximum temperature: %d\n", max);
    } else {
        printf("Month %02d: no data\n", month);
    }
}

void print_year_stats(struct temperature data[], int size) {
    int sum = 0;
    int min = 99, max = -99;
    
    if (size == 0) {
        printf("No data for year statistics\n");
        return;
    }
    
    for (int i = 0; i < size; i++) {
        sum += data[i].temp;
        if (data[i].temp < min) min = data[i].temp;
        if (data[i].temp > max) max = data[i].temp;
    }
    
    printf("Year statistics:\n");
    printf("  Average temperature: %.2f\n", (float)sum / size);
    printf("  Minimum temperature: %d\n", min);
    printf("  Maximum temperature: %d\n", max);
}
