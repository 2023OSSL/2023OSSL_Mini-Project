#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define Len_Tag 12 // EUC-KR 에서 한글 한 글자 >> 2 byte

typedef struct {
    char Date[8];
    char Name[11];
    char Comment[42];
    unsigned char Complete;
} Schedule;

int AddSchedule(Schedule *s, char (*tag)[Len_Tag]);
void ReadTag(char (*tag)[Len_Tag]);