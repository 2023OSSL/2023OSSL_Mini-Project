#include "./inc/calendar.h"

int main()
{
    // 오늘 시간 정보 불러오기
    time_t t; time(&t);
    Time today = *localtime(&t);

    DisplayCalendar(today);

    return 0;
}