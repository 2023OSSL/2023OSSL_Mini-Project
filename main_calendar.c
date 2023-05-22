#include "./inc/calendar.h"

int selectMenu();
int selectMenu_Tag();
void getEnter();

int main()
{
    Schedule *sp[NData];
    // Initialize with preset
    char tag[10][Len_Tag] = {
        "����", "����", "����"
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

            vt = mktime(&var_t);
            var_t = *localtime(&vt);

            ListSchedule(sp, var_t, count); getEnter();

        // Create Schedule
        }else if(menu == 2){
            sp[count] = (Schedule *)malloc(sizeof(Schedule));
            
            printf("������ �߰��� ��¥ �Է� (����: MM DD) >> ");
            scanf("%d %d", &var_t.tm_mon, &var_t.tm_mday);
            getchar();
            var_t.tm_mon--;

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
            printf("ǥ���� �޷� ����(YYYY MM): ");
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

    return menu;
}

void getEnter()
{
    printf("(Enter ������ ����)");
    char enter = getchar();
}
