#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

void setDate(Date *d) ;
int isLeapYear(int year);
void advanceDate(Date *d);
void displayDate(Date d);

int main() {
    Date today;

    printf("Enter today's date:\n");
    setDate(&today);

    printf("\nToday's date: ");
    displayDate(today);
    
    advanceDate(&today);
    printf("Next date: ");
    displayDate(today);

    return 0;
}


void setDate(Date *d) {
    printf("Enter day: ");
    scanf("%d", &d->day);
    printf("Enter month: ");
    scanf("%d", &d->month);
    printf("Enter year: ");
    scanf("%d", &d->year);
}

int isLeapYear(int year) {
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

void advanceDate(Date *d) {
    int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if (isLeapYear(d->year))
        daysInMonth[2] = 29;

    d->day++;

    if (d->day > daysInMonth[d->month]) {
        d->day = 1;
        d->month++;
        if (d->month > 12) {
            d->month = 1;
            d->year++;
        }
    }
}

void displayDate(Date d) {
    printf("%02d/%02d/%d\n", d.day, d.month, d.year);
}


