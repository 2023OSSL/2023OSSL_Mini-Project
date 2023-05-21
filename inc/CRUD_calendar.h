#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define Len_Tag 12
#define DataFile "schedule_data.txt"
#define Data_Path "./data"

typedef struct tm Time;

typedef struct {
    Time Time_Info;
    char Name[17];
    char Comment[62];
    char Tag[12];
    unsigned char Complete;
} Schedule;

void ReadSchedule(Schedule *s);
int AddSchedule(Schedule *s, int count, char (*tag)[Len_Tag]);
int UpdateSchedule(Schedule *s, int count, char (*tag)[Len_Tag]);
void ReadTag(char (*tag)[Len_Tag]);
int AddTag(char (*tag)[Len_Tag], int count);
int selectDataNo();
int SaveData(Schedule *s[], int count);