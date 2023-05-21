// CRUD ����� �� ���Ͽ� �ۼ����ּ���
// ������ ���� �Լ��� Schedule �ܾ�� ǥ��

#include "./CRUD_calendar.h"


// CRUD Functions
void ReadSchedule(Schedule *s)
{
    printf("");
}

int AddSchedule(Schedule *s, int count, char (*tag)[Len_Tag])
{
    int len = 0;
    printf("������ �߰��� ��¥(Date): ");
    scanf("%d", &s->Time_Info.tm_mday);
    getchar(); // ���� ���� ����

    system("cls");

    printf("���� �̸�: ");
    fgets(s->Name, 12, stdin);
    len = strlen(s->Name) - 1;
    s->Name[len] = 0; // ���� ���� ����

    system("cls");

    printf("������ ���� ������ �ۼ��Ͻÿ�(20�� �̳�).\n: ");
    fgets(s->Comment, 62, stdin);
    len = strlen(s->Comment)-1;
    s->Comment[len] = 0;

    system("cls");

    int no = 0;

    ReadTag(tag);
    printf("�±� ���� >> ");
    scanf("%d", &no);

    sprintf(s->Tag, "%s", tag[no]);

    return 1;
}

int UpdateSchedule(Schedule *s, int count, char (*tag)[Len_Tag])
{
    int len = 0;
    printf("������ ������ ��¥(Date): ");
    scanf("%d", &s->Time_Info.tm_mday);
    getchar(); // ���� ���� ����

    system("cls");

    printf("���� �̸�: ");
    fgets(s->Name, 12, stdin);
    len = strlen(s->Name) - 1;
    s->Name[len] = 0; // ���� ���� ����

    system("cls");

    printf("������ ���� ������ �ۼ��Ͻÿ�(20�� �̳�).\n: ");
    fgets(s->Comment, 62, stdin);
    len = strlen(s->Comment)-1;
    s->Comment[len] = 0;

    system("cls");

    int no = 0;

    ReadTag(tag);
    printf("�±� ���� >> ");
    scanf("%d", &no);

    sprintf(s->Tag, "%s", tag[no]);

    return 1;
}

void ReadTag(char (*tag)[Len_Tag])
{
    for(int i = 0; i < 10; i++){
        if(tag[i][0] == 0)
            break;
        
        printf("[%d] ", i+1);
        printf("%s\n", tag[i]);
    }
}

int AddTag(char (*tag)[Len_Tag], int count)
{
    if(count == 10){
        printf("** ���̻� �±׸� �߰��� �� �����ϴ� **");
        return count;
    }

    ReadTag(tag);
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


// File IO Functions
int SaveData(Schedule *s[], int count)
{
    FILE *fp;
    char filename[16];

    for(int i = 0; i < count; i++){
        sprintf(filename, "%4d%02d%02d.txt",
            s[i]->Time_Info.tm_year + 1900,
            s[i]->Time_Info.tm_mon + 1,
            s[i]->Time_Info.tm_mday);

        fp = fopen(filename, "at");
        fputs(s[i]->Name, fp);
        fputs("\n", fp);
        fputs(s[i]->Comment, fp);
        fputs("\n", fp);

        fp = fopen("filedata.txt", "at");
        fputs(filename, fp);

        fclose(fp);
    }
}

// int LoadData(){}