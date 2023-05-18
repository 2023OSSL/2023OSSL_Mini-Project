// 달력 출력, 날짜에 관한 계산 등에 필요한 함수들을 작성
#include "./calendar.h"

// 달력 출력
void DisplayCalendar(Time t)
{
    int StartDate = getStartDate(t);
    int LastDate = getLastDate(t);

    printf("=======================================================================\n");
    printf("|                                 %3s                                 |\n", getMonthName(t.tm_mon));

    int i = 0, j = 0;
    // Head
    printf("=======================================================================\n");
    printf("|   Sun   |   Mon   |   Tue   |   Wed   |   Thu   |   Fri   |   Sat   |\n");
    printf("|=====================================================================|\n");

    // Body
    char date[3];
    for(i = -StartDate + 1; j <= LastDate; i+=7){
        int cnt = 0;
        for(j = i; j < i + 7; j++){
            sprintf(date, "%2d", j);
            printf("| %2s      ", (j <= 0 || j > LastDate) ? " " : date);
            cnt++;
        }
        printf("|\n");
        if(cnt == 7){
            printf("|         |         |         |         |         |         |         |\n");
            if(j <= LastDate)
                printf("|---------|---------|---------|---------|---------|---------|---------|\n");
        }
    }
    // Tail
    printf("=======================================================================\n");
}

// 입력 달의 시작 요일 계산
int getStartDate(Time t)
{
    for(int i = 1; i < t.tm_mday; i++){
        if(t.tm_wday == 0) t.tm_wday = 6;
        else t.tm_wday--;
    }

    return t.tm_wday;
}

// 입력 달의 마지막 날짜 계산
int getLastDate(Time t)
{
    int LastDate;
    switch (t.tm_mon){
        case 0: LastDate = 31; break;
        case 1: LastDate = 28 + isLeapYear(t.tm_year + 1900); break;
        case 2: LastDate = 31; break;
        case 3: LastDate = 30; break;
        case 4: LastDate = 31; break;
        case 5: LastDate = 30; break;
        case 6: LastDate = 31; break;
        case 7: LastDate = 31; break;
        case 8: LastDate = 30; break;
        case 9: LastDate = 31; break;
        case 10: LastDate = 30; break;
        case 11: LastDate = 31; break;
    }

    return LastDate;
}

char* getMonthName(int month)
{
    switch (month){
    case 0: return "Jan";
    case 1: return "Feb";
    case 2: return "Mar";
    case 3: return "Apr";
    case 4: return "May";
    case 5: return "Jun";
    case 6: return "Jul";
    case 7: return "Aug";
    case 8: return "Sep";
    case 9: return "Oct";
    case 10: return "Nov";
    case 11: return "Dec";
    }
}

// 윤년 계산
int isLeapYear(int year)
{
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return 1;
    else return 0;
}
