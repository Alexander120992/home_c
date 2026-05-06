#ifndef TEMP_API_H
#define TEMP_API_H

struct temperature {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temp;
};

void print_month_stats(struct temperature data[], int size, int month);
void print_year_stats(struct temperature data[], int size);

#endif
