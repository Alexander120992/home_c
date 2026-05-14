#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "temp_functions.h"

void print_month_stats(struct temperature data[], int size, int month) {
    int sum = 0, count = 0;
    int min = 99, max = -99;
    int year = 0;
    
    for (int i = 0; i < size; i++) {
        if (data[i].month == month) {
            sum += data[i].temp;
            count++;
            year = data[i].year;
            if (data[i].temp < min) min = data[i].temp;
            if (data[i].temp > max) max = data[i].temp;
        }
    }
    
    if (count > 0) {
        printf("# Year Month NuValue ErValue MonthAvg MonthMax MonthMin\n");
        printf("%-2d %-4d %-5d %-6d %-7d %-8.0f %-8d %d\n", 
               0, year, month, count, 0, 
               (float)sum / count, max, min);
    }
}

void print_year_stats(struct temperature data[], int size) {
    int sum = 0;
    int min = 99, max = -99;
    
    if (size == 0) {
        return;
    }
    
    for (int i = 0; i < size; i++) {
        sum += data[i].temp;
        if (data[i].temp < min) min = data[i].temp;
        if (data[i].temp > max) max = data[i].temp;
    }
    
    printf("Year statistic: average is %.2f, max is %d, min is %d\n",
           (float)sum / size, max, min);
}

void print_all_stats(struct temperature data[], int size) {
    printf("# Year Month NuValue ErValue MonthAvg MonthMax MonthMin\n");
    for (int month = 1; month <= 12; month++) {
        int sum = 0, count = 0;
        int min = 99, max = -99;
        int year = 0;
        
        for (int i = 0; i < size; i++) {
            if (data[i].month == month) {
                sum += data[i].temp;
                count++;
                year = data[i].year;
                if (data[i].temp < min) min = data[i].temp;
                if (data[i].temp > max) max = data[i].temp;
            }
        }
        
        if (count > 0) {
            printf("%-2d %-4d %-5d %-6d %-7d %-8.0f %-8d %d\n", 
                   month - 1, year, month, count, 0, 
                   (float)sum / count, max, min);
        }
    }
    print_year_stats(data, size);
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
    
    char line[256];
    int line_number = 0;
    
    while (fgets(line, sizeof(line), file)) {
        line_number++;
        
        int year, month, day, hour, minute, temp;
        int params = sscanf(line, "%d; %d; %d; %d; %d; %d",
                            &year, &month, &day, &hour, &minute, &temp);
        
        if (params != 6) {
            params = sscanf(line, "%d;%d;%d;%d;%d;%d",
                            &year, &month, &day, &hour, &minute, &temp);
        }
        
        if (params != 6) {
            printf("Error in line %d: invalid format, skipping\n", line_number);
            continue;
        }
        
        if (month < 1 || month > 12) {
            printf("Error in line %d: invalid month, skipping\n", line_number);
            continue;
        }
        
        if (day < 1 || day > 31) {
            printf("Error in line %d: invalid day, skipping\n", line_number);
            continue;
        }
        
        if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
            printf("Error in line %d: invalid time, skipping\n", line_number);
            continue;
        }
        
        if (temp < -99 || temp > 99) {
            printf("Error in line %d: temperature out of range, skipping\n", line_number);
            continue;
        }
        
        (*data)[*size].year = year;
        (*data)[*size].month = month;
        (*data)[*size].day = day;
        (*data)[*size].hour = hour;
        (*data)[*size].minute = minute;
        (*data)[*size].temp = temp;
        
        (*size)++;
        if (*size >= capacity) {
            capacity *= 2;
            *data = (struct temperature*)realloc(*data, capacity * sizeof(struct temperature));
        }
    }
    
    fclose(file);
    return 1;
}

void free_data(struct temperature *data) {
    free(data);
}
