// CRUD ����� �� ���Ͽ� �ۼ����ּ���
// ������ ���� �Լ��� Schedule �ܾ�� ǥ��

#include "CRUD_calendar.h"

int AddSchedule(Schedule *s, char (*tag)[Len_Tag])
{
    int len = 0;
    printf("������ �߰��� ��¥(Date): ");
    scanf("%d", s->Time_Info.tm_mday);
    getchar(); // �ٹٲ� ���� ����

    system("cls");

    printf("���� �̸�: ");
    fgets(s->Name, 12, stdin);
    len = strlen(s->Name) - 1;
    s->Name[len] = 0; // �ٹٲ� ���� ����

    system("cls");

    printf("������ ���� ������ �ۼ��Ͻÿ�(20�� �̳�).\n: ");
    fgets(s->Comment, 42, stdin);
    len = strlen(s->Comment)-1;
    s->Comment[len] = 0;

    system("cls");

    ReadTag(tag);
    printf("�߰��� Tag ");
    int Num_Tag = selectDataNo();

    return 1;
}

void ReadTag(char (*tag)[Len_Tag])
{
    for(int i = 0; tag[i][0] != -1; i++){
        printf("[%d] ", i);
        printf("%s\n", tag[i]);
    }
}

int selectDataNo()
{
    int no;
    printf("��ȣ�� (���: 0)? ");
    scanf("%d", &no);

    return no + 1;
}