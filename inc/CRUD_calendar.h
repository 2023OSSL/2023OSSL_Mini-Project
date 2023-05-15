#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char Date[8];
    char Name[10];
    char Comment[20];
    unsigned char Complete;
} Schedule;

int addSchedule(Schedule *s);