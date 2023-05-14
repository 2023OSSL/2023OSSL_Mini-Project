#include <stdio.h>

typedef struct {
    char Date[8]; // 날짜 >> 0-3: 연도, 4-5: 월, 6-7: 일
    unsigned char Schedule;  // 일정이 있는지 없는지 표시하는 변수
} Schedule;

int addSchedule(Schedule *s);