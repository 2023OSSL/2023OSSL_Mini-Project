// CRUD ����� �� ���Ͽ� �ۼ����ּ���
// ������ ���� �Լ��� Schedule �ܾ�� ǥ��

#include "CRUD_calendar.h"

int AddSchedule(Schedule *s, char (*tag)[Len_Tag])
{
    int len = 0;
    printf("������ �߰��� ��¥(Date): ");
    scanf("%d", &s->Time_Info.tm_mday);
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

    return 1;
}

void ReadTag(char (*tag)[Len_Tag], int count)
{
    for(int i = 0; i < count; i++){
        printf("[%d] ", i);
        printf("%s\n", tag[i]);
    }
}

int AddTag(char (*tag)[Len_Tag], int count)
{
    if(count == 10){
        printf("** ���̻� �±׸� �߰��� �� �����ϴ� **");
        return count;
    }

    ReadTag(tag, count);
    putchar('\n');

    printf("�߰��� �±׸� (������� �Է�, �ִ� 10��): ");
    scanf("%s", tag[count]);

    return count + 1;
}

int selectDataNo()
{
    int no;
    printf("��ȣ�� (���: 0)? ");
    scanf("%d", &no);

    return no + 1;
}