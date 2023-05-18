#include "./inc/calendar.h"

int main()
{
    // 오늘 시간 정보 불러오기
    time_t t; time(&t);
    Time today = *localtime(&t);

    DisplayCalendar(today);

    // 메뉴 선택 기능
    while(1){
        if(1){

        }else if(1){

        }
    }

    return 0;
}