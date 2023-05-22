#include "./CRUD_calendar.h"

void DisplayCalendar(Time t, Schedule *s[], int count);
int getStartDate(Time t);
int getLastDate(Time t);
char* getMonthName(int month);
int isLeapYear(int year);