#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void print_all_stats(struct temperature data[], int size) {
    for (int month = 1; month <= 12; month++) {
        print_month_stats(data, size, month);
    }
    print_year_stats(data, size);
}

void add_record(struct temperature **data, int *size, struct temperature record) {
    *data = (struct temperature*)realloc(*data, (*size + 1) * sizeof(struct temperature));
    (*data)[*size] = record;
    (*size)++;
}

void delete_record(struct temperature **data, int *size, int index) {
    if (index < 0 || index >= *size) return;
    for (int i = index; i < *size - 1; i++) {
        (*data)[i] = (*data)[i + 1];
    }
    (*size)--;
    *data = (struct temperature*)realloc(*data, *size * sizeof(struct temperature));
}

void sort_by_temp(struct temperature data[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j].temp > data[j + 1].temp) {
                struct temperature temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void sort_by_date(struct temperature data[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            int date1 = data[j].year * 10000 + data[j].month * 100 + data[j].day;
            int date2 = data[j + 1].year * 10000 + data[j + 1].month * 100 + data[j + 1].day;
            if (date1 > date2) {
                struct temperature temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void print_array(struct temperature data[], int size) {
    printf("Year Month Day Hour Min Temp\n");
    for (int i = 0; i < size; i++) {
        printf("%d %02d %02d %02d %02d %d\n",
               data[i].year, data[i].month, data[i].day,
               data[i].hour, data[i].minute, data[i].temp);
    }
}

int load_csv(const char *filename, struct temperature **data, int *size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 0;
    }
    
    *size = 0;
    int capacity = 100;
    *data = (struct temperature*)malloc(capacity * sizeof(struct temperature));
    
    while (fscanf(file, "%d %d %d %d %d %d",
                  &(*data)[*size].year,
                  &(*data)[*size].month,
                  &(*data)[*size].day,
                  &(*data)[*size].hour,
                  &(*data)[*size].minute,
                  &(*data)[*size].temp) == 6) {
        (*size)++;
        if (*size >= capacity) {
            capacity *= 2;
            *data = (struct temperature*)realloc(*data, capacity * sizeof(struct temperature));
        }
    }
    
    fclose(file);
    return 1;
}
