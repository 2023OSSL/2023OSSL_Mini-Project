// CRUD 기능은 이 파일에 작성해주세요
// 일정에 대한 함수는 Schedule 단어로 표현

#include "CRUD_calendar.h"

int addSchedule(Schedule *s)
{
    printf("일정을 추가할 날짜(Date): ");
    scanf("%s", s->Date[6]);

    return 1;
}