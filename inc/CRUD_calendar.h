#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define Len_Tag 12

typedef struct tm Time;

typedef struct {
    Time Time_Info;
    char Name[11];
    char Comment[42];
    unsigned char Complete;
} Schedule;

int AddSchedule(Schedule *s, char (*tag)[Len_Tag]);
void ReadTag(char (*tag)[Len_Tag], int count);
int AddTag(char (*tag)[Len_Tag], int count);
int selectDataNo();