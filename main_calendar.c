#include "./inc/calendar.h"

int selectMenu();
int selectMenu_Tag();
void getEnter();

int main()
{
    Schedule *sp[NData];
    char tag[10][Len_Tag];
    
    int menu = 0;
    int count = LoadData(sp); getEnter();
    int index = count;
    int no;

    // 오늘 시간 정보 불러오기
    time_t t; time(&t);
    Time today = *localtime(&t);
    Time var_t;

    // 메뉴 선택 기능
    while(1){
        system("cls");
        printf("Welcome to Calendar!\n\n");
        DisplayCalendar(today);

        var_t = today;

        menu = selectMenu();
        if (menu == 0){
            system("cls");
            printf("\n\n *** 프로그램을 종료합니다 *** \n");
            break;
        }

        if((count == 0) && (menu == 1 || menu == 3 || menu == 4 || menu == 6))
            continue;
        
        // Read Schedule
        if(menu == 1){
            printf("일정을 확인할 날짜 입력 (형식: MM DD) >> ");
            scanf("%d %d", &var_t.tm_mon, &var_t.tm_mday);
            getchar();

            ListSchedule(sp, index); getEnter();

        // Create Schedule
        }else if(menu == 2){
            sp[count] = (Schedule *)malloc(sizeof(Schedule));
            
            printf("일정을 추가할 날짜 입력 (형식: MM DD) >> ");
            scanf("%d %d", &var_t.tm_mon, &var_t.tm_mday);
            getchar();

            sp[count]->Time_Info = var_t;
            
            count += AddSchedule(sp[count], count, tag);

        // Update Schedule
        }else if(menu == 3){
            printf("일정을 수정할 날짜 입력 (형식: MM DD) >> ");
            scanf("%d %d", &var_t.tm_mon, &var_t.tm_mday);

            // read func

            printf("수정할 일정 ");
            no = selectDataNo();

            if(no == 0){
                printf(">> 취소됨"); getEnter();
                continue;
            }

            int isUpdate = UpdateSchedule(sp[no-1], count, tag);
            
            if(isUpdate == 1) printf(">> 수정완료"); getEnter();

        // Delete Schedule
        }else if(menu == 4){


        // Save Data
        }else if(menu == 5){


        // Search Data
        }else if(menu == 6){


        // Move to Tag Menu
        }else if(menu == 7){


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

void getEnter()
{
    printf(" (Enter 눌러서 진행)");
    char enter = getchar();
}