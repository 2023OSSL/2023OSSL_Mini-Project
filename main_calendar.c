#include "./inc/calendar.h"

int selectMenu();

int main()
{
    Schedule *sp[40];
    int menu = 0;


    // 오늘 시간 정보 불러오기
    time_t t; time(&t);
    Time today = *localtime(&t);


    // 메뉴 선택 기능
    while(1){
        system("cls");
        DisplayCalendar(today);

        menu = selectMenu();
        if (menu == 0){
            system("cls");
            printf("\n\n *** 프로그램을 종료합니다 *** \n");
            break;
        }
        
        // Read Schedule
        if(menu == 1){
            printf("날짜 입력 (형식: MM DD) >> ");

        // Create Schedule
        }else if(menu == 2){


        // Update Schedule
        }else if(menu == 3){


        // Delete Schedule
        }else if(menu == 4){


        }else if(menu == 5){


        }else if(menu == 6){


        }else if(menu == 6){


        }
    }

    return 0;
}

int selectMenu()
{
    int menu;

    printf("\n\n- 메뉴 선택\n");
    printf("[1]일정조회   [2]일정추가   [3]일정수정\n");
    printf("[4]일정삭제   [5]저장      [6]일정검색\n");
    printf("[7]태그설정   [0]종료\n\n");
    printf("실행할 메뉴 번호 >> ");
    scanf("%d", &menu);
    
    return menu;
}

int selectMenu_Tag()
{
    int menu;

    

    return menu;
}