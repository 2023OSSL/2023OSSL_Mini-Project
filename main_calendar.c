#include "./inc/calendar.h"

int selectMenu();

int main()
{
    Schedule *sp[40];
    int menu = 0;


    // ���� �ð� ���� �ҷ�����
    time_t t; time(&t);
    Time today = *localtime(&t);


    // �޴� ���� ���
    while(1){
        system("cls");
        printf("Welcome to Calendar!\n\n");
        DisplayCalendar(today);

        menu = selectMenu();
        if (menu == 0){
            system("cls");
            printf("\n\n *** ���α׷��� �����մϴ� *** \n");
            break;
        }
        
        // Read Schedule
        if(menu == 1){
            printf("��¥ �Է� (����: MM DD) >> ");

        // Create Schedule
        }else if(menu == 2){


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