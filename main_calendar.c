// main file
#include "./inc/calendar.h"

int selectMenu();
int selectMenu_Tag();
void getEnter();

int main()
{
    Schedule *sp[NData];
    // Initialize with preset
    char tag[10][Len_Tag];
    int t_count = LoadTag(tag);
    if(t_count == 0){
        sprintf(tag[0], "����");
        sprintf(tag[1], "����");
        sprintf(tag[2], "����");
        for(int i = 3; i < 10; i++)
            sprintf(tag[i], "");
        t_count = 3;
    }

    
    int menu = 0;
    int count = LoadData(sp); getEnter();
    int index = count;
    int no;

    // Load time information
    time_t t = 0; time(&t);
    Time today = *localtime(&t);
    Time var_t = today;
    Time changed_t = today;

    // menu selection
    while(1){
        system("cls");
        printf("Welcome to Calendar!\n\n");
        DisplayCalendar(changed_t, sp, count);

        AlertUser(sp, count);
        ScheduleComplete(sp, count);

        menu = selectMenu();
        if (menu == 0){
            system("cls");
            printf("\n\n *** ���α׷��� �����մϴ� *** \n");
            break;
        }

        if((count == 0) && (menu == 1 || menu == 3 || menu == 4 || menu == 6))
            continue;
        
        // Read Schedule
        if(menu == 1){
            printf("������ Ȯ���� ��¥ �Է� (����: MM DD) >> ");
            scanf("%d %d", &var_t.tm_mon, &var_t.tm_mday);
            getchar();
            var_t.tm_mon--;
            
            time_t vt = 0;

            vt = mktime(&var_t);
            var_t = *localtime(&vt);

            ListSchedule(sp, var_t, count); getEnter();

            printf("%d/%d\n", sp[0]->Time_Info.tm_mon+1, sp[0]->Time_Info.tm_mday);
            printf("%d/%d\n", sp[1]->Time_Info.tm_mon+1, sp[1]->Time_Info.tm_mday);

        // Create Schedule
        }else if(menu == 2){
            sp[count] = (Schedule *)malloc(sizeof(Schedule));
            
            printf("������ �߰��� ��¥ �Է� (����: MM DD) >> ");
            scanf("%d %d", &var_t.tm_mon, &var_t.tm_mday);
            getchar();
            var_t.tm_mon--;

            time_t vt = 0;

            vt = mktime(&var_t);
            var_t = *localtime(&vt);

            sp[count]->Time_Info = var_t;
            
            count += AddSchedule(sp[count], count, tag);
            
        // Update Schedule
        }else if(menu == 3){
            printf("������ ������ ��¥ �Է� (����: MM DD) >> ");
            scanf("%d %d", &var_t.tm_mon, &var_t.tm_mday);
            getchar();
            var_t.tm_mon--;

            ListSchedule(sp, var_t, count);

            printf("������ ���� ");
            no = selectDataNo();

            if(no == 0){
                printf(">> ��ҵ�"); getEnter();
                continue;
            }

            int isUpdate = UpdateSchedule(sp[no-1], count, tag);
            if(isUpdate == 1) printf(">> �����Ϸ�");
            getEnter();

        // Delete Schedule
        }else if(menu == 4){
            Time selectedDate;
            printf("������ ������ ��¥ �Է�(����: MM DD) >> ");
            scanf("%d %d", &selectedDate.tm_mon, &selectedDate.tm_mday);
            getchar();
            selectedDate.tm_mon--;

            ListSchedule(sp, var_t, count);

            printf("������ ���� ");
            int selectedScheduleNo = selectDataNo();  // Declare and assign selectedScheduleNo

            if (selectedScheduleNo == 0) {
                printf(">> ��ҵ� "); 
                getEnter();
                continue;
            }

            int isDeleted = DeleteSchedule(sp, count, tag, selectedDate, selectedScheduleNo);  // Pass selectedScheduleNo to the function
            if (isDeleted) {
                count--;
            }
            getEnter();

        // Save Data
        }else if(menu == 5){
            SaveData(sp, count); getEnter();

        // Search Data
        }else if(menu == 6){
            SearchData(sp, count, tag);

        // Move to Tag Menu
        }else if(menu == 7){
            int t_menu = selectMenu_Tag();
            if(t_menu == 1){
                ReadTag(tag); getEnter();
            } else if(t_menu == 2)
                t_count += AddTag(tag, t_count);
        
        // Change DisplayCalendar
        }else if(menu == 8){
            printf("ǥ���� �޷� ����(YYYY MM): ");
            scanf("%d %d", &changed_t.tm_year, &changed_t.tm_mon);
            getchar();
            changed_t.tm_year -= 1900; changed_t.tm_mon -= 1; changed_t.tm_mday = 1;
            
            time_t vt = 0;

            vt = mktime(&changed_t);
            changed_t = *localtime(&vt);
        }
    }

    for(int i = 0; i < count; i++)
        free(sp[i]);

    SaveTag(tag, t_count);

    return 0;
}

int selectMenu()
{
    int menu;

    printf("\n\n- �޴� ����\n");
    printf("[1]������ȸ   [2]�����߰�   [3]��������\n");
    printf("[4]��������   [5]��������   [6]�±׺� ���� ��ȸ\n");
    printf("[7]�±׼���   [8]�޷º���   [0]����\n\n");
    printf("������ �޴� ��ȣ >> ");
    scanf("%d", &menu);
    
    return menu;
}

int selectMenu_Tag()
{
    int menu;

    printf("\n\n- �޴� ����\n");
    printf("[1]�±���ȸ   [2]�±��߰�\n");
    printf("������ �޴� ��ȣ >> ");
    scanf("%d", &menu);
    getchar();

    return menu;
}

void getEnter()
{
    printf("(Enter ������ ����)");
    char enter = getchar();
}