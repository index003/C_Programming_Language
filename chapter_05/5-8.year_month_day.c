#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
int main() {
    int day1,day2;
    int pmonth1, pmonth2;
    int pday1, pday2;

    printf("day_of_year(2022, 3, 10) ");
    day1 = day_of_year(2022, 3, 10);
    printf("%d\n\n", day1);

    printf("day_of_year(2022, 2, 30) ");
    day2 = day_of_year(2022, 2, 30);
    printf("%d\n\n", day2);

    printf("month_day(2022, 69 ");
    month_day(2022, 69, &pmonth1, &pday1);
    printf("month = %d, day = %d\n\n", pmonth1, pday1);

    printf("month_day(2022, 369 ");
    month_day(2022, 369, &pmonth2, &pday2);
    printf("month = %d, day = %d\n\n", pmonth2, pday2);
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) {
    int leap, i;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (month > 12 || month < 1) {
        printf("month must between 1 - 12\n");
        return -1;
    }
    if (day < 1) {
        printf("day must garther than 0\n");
        return -1;
    } else if (day > daytab[leap][month]) {
        printf("there are only %d days in %d month\n", daytab[leap][month], month);
        return -1;
    }

    for (i = 1; i < month; i++) {
        day += daytab[leap][i];
    }
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int leap, i;
    int max_yearday = 0;
    if (year < 1000) {
        printf("year should be greater than 1000\n");
        *pmonth = -1;
        *pday = -1;
        return;
    }

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    
    for (int m = 1; m <= 12; m++) {
       max_yearday += daytab[leap][m]; 
    }

    if (yearday < 1) {
        printf("day must garther than 0\n");
        *pmonth = -1;
        *pday = -1;
        return;
    } else if (yearday > max_yearday) {
        printf("there are only %d days in %d year\n", max_yearday, year);
        *pmonth = -1;
        *pday = -1;
        return;
    }
    for (i = 1; yearday > daytab[leap][i]; i++) {
        yearday -= daytab[leap][i];
    }
    *pmonth = i;
    *pday = yearday;
}
