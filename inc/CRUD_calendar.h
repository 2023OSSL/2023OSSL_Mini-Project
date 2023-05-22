#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define Len_Name 17
#define Len_Comment 62
#define Len_Tag 17
#define NData 40
#define DataFile "schedule_data.txt"

typedef struct tm Time;

typedef struct {
    Time Time_Info;
    char Name[Len_Name];
    char Comment[Len_Comment];
    char Tag[Len_Tag];
    unsigned char Complete;
} Schedule;

void ReadSchedule(Schedule *s);
void ListSchedule(Schedule *s[], Time t, int index);
int AddSchedule(Schedule *s, int count, char (*tag)[Len_Tag]);
int UpdateSchedule(Schedule *s, int count, char (*tag)[Len_Tag]);
void ReadTag(char (*tag)[Len_Tag]);
int AddTag(char (*tag)[Len_Tag], int count);
int selectDataNo();
int SaveData(Schedule *s[], int count);
int LoadData(Schedule *s[]);