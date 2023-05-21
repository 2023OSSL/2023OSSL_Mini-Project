#include "./inc/calendar.h"

int selectMenu();

int main()
{
    Schedule *sp[40];
    char tag[10][Len_Tag];
    
    int menu = 0;
    int count = 0;

    // ���� �ð� ���� �ҷ�����
    time_t t; time(&t);
    Time today = *localtime(&t);
    Time var_t;

    // �޴� ���� ���
    while(1){
        system("cls");
        printf("Welcome to Calendar!\n\n");
        DisplayCalendar(today);

        var_t = today;

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
            printf("��¥ �Է� (����: MM DD) >> ");
            scanf("%d %d", var_t.tm_mon, var_t.tm_mday);

        // Create Schedule
        }else if(menu == 2){
            sp[count] = (Schedule *)malloc(sizeof(Schedule));
            
            printf("������ �߰��� ��¥ �Է� (����: MM DD) >> ");
            scanf("%d %d", var_t.tm_mon, var_t.tm_mday);

            sp[count]->Time_Info = var_t;
            
            count += AddSchedule(sp[count], tag); 
            
        
        // Update Schedule
        }else if(menu == 3){


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

    printf("\n\n- �޴� ����\n");
    printf("[1]������ȸ   [2]�����߰�   [3]��������\n");
    printf("[4]��������   [5]����      [6]�����˻�\n");
    printf("[7]�±׼���   [0]����\n\n");
    printf("������ �޴� ��ȣ >> ");
    scanf("%d", &menu);
    
    return menu;
}

int selectMenu_Tag()
{
    int menu;



    return menu;
}