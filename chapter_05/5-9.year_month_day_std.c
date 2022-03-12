#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
int main() {
    int day1,day2;
    int pmonth1, pmonth2, pmonth3;
    int pday1, pday2, pday3;

    printf("day_of_year(2022, 3, 10) ");
    day1 = day_of_year(2022, 3, 10);
    printf("days = %d\n\n", day1);

    printf("day_of_year(2022, 3, 11) ");
    day2 = day_of_year(2022, 3, 11);
    printf("days = %d\n\n", day2);

    printf("month_day(2022, 69) ");
    month_day(2022, 69, &pmonth1, &pday1);
    printf("month = %d, day = %d\n\n", pmonth1, pday1);

    printf("month_day(2022, 70) ");
    month_day(2022, 70, &pmonth3, &pday3);
    printf("month = %d, day = %d\n\n", pmonth3, pday3);

    printf("month_day(2022, 369) ");
    month_day(2022, 369, &pmonth2, &pday2);
    printf("month = %d, day = %d\n\n", pmonth2, pday2);
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) {
    int leap;
    char *p;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    p = daytab[leap];
    while (--month) {
        day += *++p;
    }
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int leap;
    char *p;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    p = daytab[leap];
    while (yearday > *++p) {
        yearday -= *p;
    }
    *pmonth = p - *(daytab + leap);
    *pday = yearday;
}
