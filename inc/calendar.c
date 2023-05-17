// 달력 출력, 날짜에 관한 계산 등에 필요한 함수들을 작성
#include "calendar.h"

// 달력 출력
void DisplayCalendar()
{

}

// 입력 달 시작 요일 계산
int getStartDay(int year, int month)
{
    return 0;    
}

// 윤년 계산
int isLeapYear(int year)
{
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return 1;
    else return 0;
}
