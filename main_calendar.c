#include "./inc/calendar.h"

int selectMenu();
int selectMenu_Tag();
void getEnter();

int main()
{
    Schedule *sp[NData];
    // Initialize with preset
    char tag[10][Len_Tag] = {
        "과제", "시험", "팀플"
    };
    int t_count = 3;
    
    int menu = 0;
    int count = LoadData(sp); getEnter();
    int index = count;
    int no;

    // Load time information
    time_t t, vt; time(&t);
    Time today = *localtime(&t);
    Time var_t = today;
    Time changed_t = today;

    // menu selection
    while(1){
        // system("cls");
        printf("Welcome to Calendar!\n\n");
        DisplayCalendar(changed_t);

        AlertUser(sp, count);

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
            var_t.tm_mon--;

            vt = mktime(&var_t);
            var_t = *localtime(&vt);

            ListSchedule(sp, var_t, count); getEnter();

        // Create Schedule
        }else if(menu == 2){
            sp[count] = (Schedule *)malloc(sizeof(Schedule));
            
            printf("일정을 추가할 날짜 입력 (형식: MM DD) >> ");
            scanf("%d %d", &var_t.tm_mon, &var_t.tm_mday);
            getchar();
            var_t.tm_mon--;

            vt = mktime(&var_t);
            var_t = *localtime(&vt);

            sp[count]->Time_Info = var_t;
            
            count += AddSchedule(sp[count], count, tag);
            
        // Update Schedule
        }else if(menu == 3){
            printf("일정을 수정할 날짜 입력 (형식: MM DD) >> ");
            scanf("%d %d", &var_t.tm_mon, &var_t.tm_mday);
            getchar();
            var_t.tm_mon--;

            ListSchedule(sp, var_t, count);

            printf("수정할 일정 ");
            no = selectDataNo();

            if(no == 0){
                printf(">> 취소됨"); getEnter();
                continue;
            }

            int isUpdate = UpdateSchedule(sp[no-1], count, tag);
            if(isUpdate == 1) printf(">> 수정완료");
            getEnter();

        // Delete Schedule
        }else if(menu == 4){


        // Save Data
        }else if(menu == 5){
            SaveData(sp, count); getEnter();

        // Search Data
        }else if(menu == 6){
            SearchData(sp, count, tag);

        // Move to Tag Menu
        }else if(menu == 7){
            int t_menu = selectMenu_Tag();
            if(t_menu == 1)
                ReadTag(tag);
            else if(t_menu == 2)
                t_count += AddTag(tag, t_count);
        
        // Change DisplayCalendar
        }else if(menu == 8){
            printf("표시할 달력 연월(YYYY MM): ");
            scanf("%d %d", &changed_t.tm_year, &changed_t.tm_mon);
            getchar();
            changed_t.tm_year -= 1900; changed_t.tm_mon -= 1; changed_t.tm_mday = 1;
            
            vt = mktime(&changed_t);
            changed_t = *localtime(&vt);
        }
    }

    for(int i = 0; i < count; i++)
        free(sp[i]);

    return 0;
}

int selectMenu()
{
    int menu;

    printf("\n\n- 메뉴 선택\n");
    printf("[1]일정조회   [2]일정추가   [3]일정수정\n");
    printf("[4]일정삭제   [5]내용저장   [6]태그별 일정 조회\n");
    printf("[7]태그설정   [8]달력보기   [0]종료\n\n");
    printf("실행할 메뉴 번호 >> ");
    scanf("%d", &menu);
    
    return menu;
}

int selectMenu_Tag()
{
    int menu;

    printf("\n\n- 메뉴 선택\n");
    printf("[1]태그조회   [2]태그추가\n");
    printf("실행할 메뉴 번호 >> ");
    scanf("%d", &menu);

    return menu;
}

void getEnter()
{
    printf("(Enter 눌러서 진행)");
    char enter = getchar();
}
